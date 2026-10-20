_Head:
  adr   x1, _Payload    /* Set _Entry address */
  b     _Start          /* Jump to the real code */

#if REQUIRES_KERNEL_HEADER == 1
_StackBase:
  .quad FD_BASE         /* Text Offset */

_StackSize:
  .quad FD_SIZE + (_Payload - _Head) /* Complete shim and payload */
  .quad 0               /* Flags */
  .quad 0               /* Reserved */
  .quad 0               /* Reserved */
  .quad 0               /* Reserved */
  .ascii "ARM\x64"      /* ARM64 Magic */
  .long 0               /* Reserved */
#endif

_Start:
  mov   x4, x1
  ldr   x5, =FD_BASE
  cmp   x4, x5
  beq   _Entry
  ldr   x6,  =FD_SIZE

_CopyLoop:
  ldp   x2, x3, [x4], #16
  stp   x2, x3, [x5], #16
  subs  x6, x6, #16
  b.ne  _CopyLoop
  ldr   x5, =FD_BASE

_Entry:
  /* Publish the copied instructions before executing them. */
  dsb   sy
  mrs   x9, ctr_el0
  ubfx  x9, x9, #16, #4
  mov   x10, #4
  lsl   x9, x10, x9
  sub   x10, x9, #1
  bic   x8, x5, x10
  ldr   x7, =FD_SIZE
  add   x7, x5, x7

_CleanLoop:
  dc    cvac, x8
  add   x8, x8, x9
  cmp   x8, x7
  b.lo  _CleanLoop
  dsb   sy
  ic    iallu
  dsb   sy
  isb

  /* hongkong: paint test blocks straight into the framebuffer before handing
     over, so a later black screen can be told apart from a panel that was
     never driven. Red at the top-left of row 600, green lower down. */
  ldr   x11, =0xF8C60000
  movz  w12, #0x0000
  movk  w12, #0xFF00, lsl #16
  mov   x13, #0x0A80000        /* 600 rows * 4480 px * 4 bytes */
  add   x11, x11, x13
  mov   x13, #512
_hk_red:
  str   w12, [x11], #4
  subs  x13, x13, #1
  b.ne  _hk_red
  ldr   x11, =0xF8C60000
  mov   x13, #0x0F00000
  add   x11, x11, x13
  movz  w12, #0x00FF
  mov   x13, #512
_hk_green:
  str   w12, [x11], #4
  subs  x13, x13, #1
  b.ne  _hk_green

  br    x5

_Dead:
  b     _Dead

.text
.ltorg
.align 4

_Payload:
