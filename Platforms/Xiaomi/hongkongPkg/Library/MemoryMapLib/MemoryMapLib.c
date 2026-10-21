// SPDX-License-Identifier: BSD-3-Clause
// Regions come from this device's DTBs (uefi_dtb_a).
// All are declared reserved; the attribute encoding is not yet decoded.
#include <Library/MemoryMapLib.h>

STATIC EFI_MEMORY_REGION_DESCRIPTOR gMemoryDescriptor[] = {
  {"NOMAP", 0x80000000, 0x01960000, AddMem, MEM_RES, SYS_MEM_CAP, Reserv, UNCACHED_UNBUFFERED},
  {"RSRV0", 0x81960000, 0x000A0000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, WRITE_BACK},
  {"XBL_DT", 0x81A00000, 0x00060000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, WRITE_BACK},
  {"AOP", 0x81C00000, 0x000A0000, AddMem, MEM_RES, SYS_MEM_CAP, Reserv, UNCACHED_UNBUFFERED},
  {"TME", 0x81CA0000, 0x00044000, AddMem, MEM_RES, SYS_MEM_CAP, Reserv, UNCACHED_UNBUFFERED},
  {"UEFI_Log", 0x81CE4000, 0x00040000, AddMem, MEM_RES, SYS_MEM_CAP, Reserv, UNCACHED_UNBUFFERED},
  {"VOLTAGE_PLAN", 0x81E00000, 0x00100000, AddMem, MEM_RES, SYS_MEM_CAP, Reserv, UNCACHED_UNBUFFERED},
  {"PDP_NS", 0x81F00000, 0x00100000, AddMem, MEM_RES, SYS_MEM_CAP, Reserv, UNCACHED_UNBUFFERED},
  {"SOCCP_SDI", 0x823A0000, 0x00040000, AddMem, MEM_RES, SYS_MEM_CAP, Reserv, UNCACHED_UNBUFFERED},
  {"QUP_FW", 0x82460000, 0x00018000, AddMem, MEM_RES, SYS_MEM_CAP, Reserv, UNCACHED_UNBUFFERED},
  {"PvmFw", 0x824A0000, 0x00100000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, WRITE_BACK},
  {"TZ_STAT", 0x82600000, 0x00100000, AddMem, MEM_RES, SYS_MEM_CAP, Reserv, UNCACHED_UNBUFFERED},
  {"SMEM", 0x82700000, 0x00400000, AddMem, MEM_RES, SYS_MEM_CAP, Reserv, DEVICE},
  {"HLOS1", 0x83E00000, 0x03800000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv, WRITE_BACK},
  {"PIL_Reserved", 0x87600000, 0x1E400000, AddMem, MEM_RES, SYS_MEM_CAP, Reserv, UNCACHED_UNBUFFERED},
  {"Display_Demura", 0xA5A00000, 0x02C80000, AddMem, MEM_RES, SYS_MEM_CAP, Reserv, WRITE_THROUGH},
  {"DBI_Dump", 0xA8680000, 0x03F70000, NoHob, MMAP_IO, SYS_MEM_CAP, Conv, UNCACHED_UNBUFFERED},
  {"DXE_Heap", 0xAC5F0000, 0x0C010000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv, WRITE_BACK},
  {"WLAN_MSA", 0xB8600000, 0x00C00000, AddMem, MEM_RES, SYS_MEM_CAP, Reserv, UNCACHED_UNBUFFERED},
  {"DXE_Heap2", 0xB9200000, 0x04300000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv, WRITE_BACK},
  {"FV_Region", 0xC6400000, 0x00400000, AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK},
  {"UEFI_FD", 0xC6800000, 0x00D00000, AddMem, SYS_MEM, SYS_MEM_CAP, BsCode, WRITE_BACK},
  {"UEFI_LIBUFDT_BUFFER", 0xC7500000, 0x00100000, AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK},
  {"Info_Blk", 0xC7600000, 0x00001000, AddMem, SYS_MEM, SYS_MEM_CAP, RtData, WRITE_BACK},
  {"Log_Buffer", 0xC7601000, 0x0000F000, AddMem, SYS_MEM, SYS_MEM_CAP, RtData, WRITE_BACK},
  {"CPU_Vectors", 0xC7610000, 0x00001000, AddMem, SYS_MEM, SYS_MEM_CAP, BsCode, WRITE_BACK},
  {"MMU_PageTables", 0xC7611000, 0x00003000, AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK},
  {"SEC_Heap", 0xC7614000, 0x000B0000, AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK},
  {"UEFI_Stack", 0xC76C4000, 0x00030000, AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK},
  {"UEFI_RESV", 0xC76F4000, 0x0000C000, AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK},
  {"UEFI_DTB", 0xC7700000, 0x00100000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, WRITE_BACK},
  {"Kernel", 0xC7800000, 0x10000000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, WRITE_BACK},
  {"XBL_Ramdump", 0xD7800000, 0x001C0000, AddMem, MEM_RES, SYS_MEM_CAP, Reserv, UNCACHED_UNBUFFERED},
  {"Global_SYNC", 0xD7A00000, 0x00200000, AddMem, MEM_RES, SYS_MEM_CAP, Reserv, UNCACHED_UNBUFFERED},
  {"TAGS", 0xD8800000, 0x075A0000, AddMem, MEM_RES, SYS_MEM_CAP, Reserv, UNCACHED_UNBUFFERED},
  {"Display_Reserved", 0xF8C60000, 0x02B00000, AddMem, MEM_RES, SYS_MEM_CAP, Reserv, UNCACHED_UNBUFFERED},

  /* The peripheral windows, named as the vendor memory map names them. Vendor
   * drivers touch their own registers through these, and none of them are DRAM,
   * so each was left unmapped and the first access raised a second-level
   * translation fault - QcomHWWDogDxe at 0x03AD1004 was the first of them.
   *
   * Add one at a time. The full set is about 224 MB of page tables and stopped
   * SEC before it could print anything, while this shorter set boots. QUP comes
   * first because the DebugLib linked into the prebuilt drivers writes its
   * output to that UART, so the first DEBUG in any of them touches it. */
  {"QUP", 0x00800000, 0x00300000, AddMem, MMAP_IO, SYS_MEM_CAP, Reserv, UNCACHED_UNBUFFERED},
  {"CORE_TOP_CSR", 0x03A00000, 0x00200000, AddMem, MMAP_IO, SYS_MEM_CAP, Reserv, UNCACHED_UNBUFFERED},
  {"USB", 0x0A600000, 0x00200000, AddMem, MMAP_IO, SYS_MEM_CAP, Reserv, UNCACHED_UNBUFFERED},
  {"AOSS", 0x0B000000, 0x04000000, AddMem, MMAP_IO, SYS_MEM_CAP, Reserv, UNCACHED_UNBUFFERED},
};

VOID
GetMemoryMap (
  OUT EFI_MEMORY_REGION_DESCRIPTOR **MemoryDescriptor,
  OUT UINT8                         *MemoryDescriptorCount)
{
  // Pass Data
  *MemoryDescriptor      = gMemoryDescriptor;
  *MemoryDescriptorCount = ARRAY_SIZE (gMemoryDescriptor);
}
