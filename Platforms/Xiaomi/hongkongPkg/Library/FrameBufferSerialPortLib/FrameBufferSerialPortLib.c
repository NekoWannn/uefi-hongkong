/**
  Frame buffer serial port for hongkong.

  The device has no accessible UART and VENDOR_HW=0 means no display driver
  runs before DXE, so DEBUG() output has nowhere to go. This library pretends
  to be the serial port and paints the characters straight into the panel's
  frame buffer at 0xF8C60000, which the shim has already proven writable.

  Only SerialPortLib is replaced: BaseDebugLibSerialPort still does the
  formatting, so any DEBUG() in SEC, PEI or DXE lands on the screen.
**/

#include <Base.h>
#include <Library/SerialPortLib.h>

#define FB_BASE     ((volatile UINT32 *)0xF8C60000UL)
#define FB_WIDTH    1120U
#define FB_HEIGHT   2436U
/* Row stride in UINT32 units: 4480 bytes per row / 4. Using the byte stride
 * here advanced four rows per line and scattered the glyphs diagonally. */
#define FB_STRIDE   1120U
#define CELL_W      8U
#define CELL_H      16U
#define MARGIN_Y    420U
#define MARGIN_X    8U
#define COLS        136U
/* Rows that fit between MARGIN_Y and the bottom of the panel: 126 at 16px. */
#define ROWS        ((FB_HEIGHT - MARGIN_Y) / CELL_H)
#define FG          0xFFFFFFFFU
#define BG          0xFF000000U

static const unsigned char font8x16[95][16] = {
#include "font8x16.inc"
};

/* Console state lives at a fixed physical address, not in a static: this
 * library is linked into every module that uses DEBUG, so a static gives each
 * of them its own cursor - SEC would write at row 18 while DxeCore wrote at row
 * 0, clobbering the log and restarting the line numbers. */
#define CON_SHARED  ((volatile CON_STATE *)0xC6C00000UL)
#define CON_MAGIC   0x53474F4CU   /* 'LGOS' */

typedef struct {
  UINT32 Lock;
  UINT32 Magic;
  UINT32 Row;
  UINT32 Col;
  UINT32 LineNo;
  UINT32 Pending;
  UINT32 Panic;
} CON_STATE;

/* Several modules, and later several cores, write through the same cursor.
 * A tiny exclusive-monitor spinlock keeps a line from being torn mid-glyph. */
STATIC
VOID
ConAcquire (
  VOID
  )
{
  UINTN addr = (UINTN)&CON_SHARED->Lock;
  __asm__ volatile (
    "1: ldxr  w1, [%0]\n"
    "   cbnz  w1, 1b\n"
    "   mov   w1, #1\n"
    "   stxr  w2, w1, [%0]\n"
    "   cbnz  w2, 1b\n"
    :
    : "r"(addr)
    : "w1", "w2", "memory"
    );
}

STATIC
VOID
ConRelease (
  VOID
  )
{
  const UINT32 zero = 0;
  __asm__ volatile (
    "stlr  %w0, [%1]\n"
    :
    : "r"(zero), "r"((UINTN)&CON_SHARED->Lock)
    : "memory"
    );
}

#define mRow          (CON_SHARED->Row)
#define mCol          (CON_SHARED->Col)
#define mLineNo       (CON_SHARED->LineNo)
#define mPendingPrefix (CON_SHARED->Pending)
#define mPanic        (CON_SHARED->Panic)

/* Row clearing was removed: each cell paints its own background. */

STATIC
VOID
FbPutChar (
  IN CHAR8 Ch
  )
{
  UINT32 glyph;
  UINT32 y;
  UINT32 bit;

  if (Ch == '\n') {
    mCol = 0;
    mRow++;
    /* Number the next line so the screen shows how much was really printed. */
    mPendingPrefix = TRUE;
  } else if (Ch == '\r') {
    mCol = 0;
    return;
  } else {
    if (Ch < 0x20 || Ch > 0x7E) {
      Ch = '?';
    }
    if (mPendingPrefix) {
      CHAR8 digits[10];
      UINT32 n = 0;
      UINT32 v = mLineNo++;
      mPendingPrefix = FALSE;
      do {
        digits[n++] = (CHAR8)('0' + (v % 10));
        v /= 10;
      } while (v != 0);
      while (n > 0) {
        FbPutChar (digits[--n]);
      }
      FbPutChar (':');
      FbPutChar (' ');
    }
    if (mCol >= COLS) {
      mCol = 0;
      mRow++;
    }

    /* No row clear here: each cell already paints its own background, and
     * clearing the row erased every earlier character on it, leaving only the
     * last one visible per line. */
    glyph = (UINT32)(Ch - 0x20);
    for (y = 0; y < CELL_H; y++) {
      UINT32 row = MARGIN_Y + mRow * CELL_H + y;
      volatile UINT32 *line;
      if (row >= FB_HEIGHT) {
        break;
      }
      line = FB_BASE + row * FB_STRIDE + MARGIN_X + mCol * CELL_W;
      for (bit = 0; bit < CELL_W; bit++) {
        line[bit] = (font8x16[glyph][y] & (0x80 >> bit)) ? FG : BG;
      }
    }
    mCol++;
  }

  /* The display controller scans memory while the CPU writes through a
   * cacheable mapping, so push the glyph out to memory before it is scanned. */
  {
    UINTN start = (UINTN)FB_BASE + (MARGIN_Y + mRow * CELL_H) * FB_STRIDE * 4;
    UINTN end   = start + CELL_H * FB_STRIDE * 4;
    UINTN p;
    for (p = start & ~(UINTN)63; p < end; p += 64) {
      __asm__ volatile("dc civac, %0" :: "r"(p) : "memory");
    }
    __asm__ volatile("dsb sy" ::: "memory");
  }

  if (mRow >= ROWS) {
    /* Once a panic starts the first lines are the ones that matter, so stop
     * drawing instead of wrapping: the panel keeps the opening of the report
     * and nothing overwrites it. */
    if (mPanic) {
      return;
    }
    /* Wrap: wipe the log area so the next screen always reads top-down and
     * cannot be confused with leftovers from an earlier boot. */
    UINT32 yy;
    UINT32 xx;
    for (yy = MARGIN_Y; yy < MARGIN_Y + ROWS * CELL_H && yy < FB_HEIGHT; yy++) {
      volatile UINT32 *ln = FB_BASE + yy * FB_STRIDE + MARGIN_X;
      for (xx = 0; xx < COLS * CELL_W; xx++) {
        ln[xx] = BG;
      }
    }
    mRow = 0;
    mCol = 0;
  }
}

RETURN_STATUS
EFIAPI
SerialPortInitialize (
  VOID
  )
{
  UINT32 y;
  UINT32 x;

  /* Every module that uses DEBUG links its own copy of this library, so this
   * runs once per module. Only the first one may clear the screen and reset the
   * cursor; the rest must keep writing where the previous module stopped. */
  if (CON_SHARED->Magic == CON_MAGIC) {
    return RETURN_SUCCESS;
  }

  for (y = MARGIN_Y; y < MARGIN_Y + ROWS * CELL_H && y < FB_HEIGHT; y++) {
    volatile UINT32 *line = FB_BASE + y * FB_STRIDE + MARGIN_X;
    for (x = 0; x < COLS * CELL_W; x++) {
      line[x] = BG;
    }
  }
  mRow = 0;
  mCol = 0;
  mLineNo = 1;
  mPendingPrefix = TRUE;
  CON_SHARED->Magic = CON_MAGIC;
  return RETURN_SUCCESS;
}

UINTN
EFIAPI
SerialPortWrite (
  IN UINT8 *Buffer,
  IN UINTN  NumberOfBytes
  )
{
  UINTN i;

  /* Hold the lock for the whole buffer: locking per character still lets two
   * modules interleave their messages into one garbled line. */
  ConAcquire ();
  if (!mPanic) {
    /* Freeze on the banner that opens a fault, not on the ASSERT that closes
     * it: the register dump between them is the part worth reading. */
    for (i = 0; i + 5 < NumberOfBytes; i++) {
      if ((Buffer[i] == '!' && Buffer[i + 1] == '!' &&
           Buffer[i + 2] == '!' && Buffer[i + 3] == '!') ||
          (Buffer[i] == 'A' && Buffer[i + 1] == 'S' && Buffer[i + 2] == 'S' &&
           Buffer[i + 3] == 'E' && Buffer[i + 4] == 'R' && Buffer[i + 5] == 'T')) {
        /* Start the report at the top of the panel and stop scrolling once it
         * fills, so the opening lines of a panic survive. */
        UINT32 yy;
        UINT32 xx;
        for (yy = MARGIN_Y; yy < MARGIN_Y + ROWS * CELL_H && yy < FB_HEIGHT; yy++) {
          volatile UINT32 *ln = FB_BASE + yy * FB_STRIDE + MARGIN_X;
          for (xx = 0; xx < COLS * CELL_W; xx++) {
            ln[xx] = BG;
          }
        }
        mRow = 0;
        mCol = 0;
        mPanic = 1;
        break;
      }
    }
  }
  for (i = 0; i < NumberOfBytes; i++) {
    FbPutChar ((CHAR8)Buffer[i]);
  }
  ConRelease ();
  return NumberOfBytes;
}

UINTN
EFIAPI
SerialPortRead (
  OUT UINT8 *Buffer,
  IN  UINTN  NumberOfBytes
  )
{
  (void)Buffer;
  (void)NumberOfBytes;
  return 0;
}

BOOLEAN
EFIAPI
SerialPortPoll (
  VOID
  )
{
  return FALSE;
}

RETURN_STATUS
EFIAPI
SerialPortSetControl (
  IN UINT32 Control
  )
{
  (void)Control;
  return RETURN_SUCCESS;
}

RETURN_STATUS
EFIAPI
SerialPortGetControl (
  OUT UINT32 *Control
  )
{
  *Control = 0;
  return RETURN_SUCCESS;
}

RETURN_STATUS
EFIAPI
SerialPortSetAttributes (
  IN OUT UINT64              *BaudRate,
  IN OUT UINT32              *ReceiveFifoDepth,
  IN OUT UINT32              *Timeout,
  IN OUT EFI_PARITY_TYPE     *Parity,
  IN OUT UINT8               *DataBits,
  IN OUT EFI_STOP_BITS_TYPE  *StopBits
  )
{
  (void)BaudRate;
  (void)ReceiveFifoDepth;
  (void)Timeout;
  (void)Parity;
  (void)DataBits;
  (void)StopBits;
  return RETURN_SUCCESS;
}
