# hongkong bring-up

Xiaomi 18 Pro (`M610BB`, `hongkong`), SM8950 / Qualcomm `maili` (based on `hawi`).
Not hardware validated; nothing here is a ready-to-flash image.

## Where the numbers come from

Everything below was read out of the device's own partitions, not guessed:

| Source | What it gave |
|---|---|
| `uefi_a` (`/dev/block/sde1`, 5 MiB) | ELF64 header: FD base/size; FV with 1305 extracted files |
| `uefi_dtb_a` (`/dev/block/sde3`, 400 KB) | three DTBs: base `qcom,hawi-uefi`, device overlay, `qcom,maili-default-uefi` overlay |

The stock `uefi_a` image starts with an ELF64 (`ET_EXEC`, `EM_AARCH64`):

```
e_entry = 0xC6800000
PT_LOAD off=0x1000 vaddr=paddr=0xC6800000 filesz=memsz=0x369000
```

so `uefi_fd.base = 0xC6800000` and `uefi_fd.size = 0x369000`, exactly what
`Resources/Configs/hongkong.toml` records. The firmware volume header (`_FVH`)
sits at file offset `0x1000` with FV length `0x368000`.

## Panel

The stock panel is 1120x2436. The framebuffer sits at `0xF8C60000` for
`0x2B00000` bytes per the platform DTB `memorymap`, so
`PcdFrameBufferWidth=1120`, `PcdFrameBufferHeight=2436`, colour depth 32.

Unlike sheng there is no `Display Reserved` region to inherit: whether ABL
keeps the panel scanning out across the handoff has not been observed yet, and
the appended DTB may still need a splash node for that. First boot should be
treated as "panel state unknown".

## First boot configuration

`HONGKONG_VENDOR_HW = 0` (default): Mu drivers only, `SimpleFbDxe` publishes the
GOP on the framebuffer above, no vendor binaries are referenced. This is the
configuration the first build targets.

`HONGKONG_VENDOR_HW = 1` additionally loads the stock vendor drivers. The `.inc`
files now point at `Binaries/hongkong/...`, which is empty: the vendor FFS
modules still have to be imported from this device's `uefi_a` image (the same
GUID/PE/DEPEX-preserving import sheng used). Until that import exists, never
enable this switch - the build would fail on missing INF files.

`USE_CUSTOM_DISPLAY_DRIVER` stays 0 for the same reason.

## Known gaps

- `Library/MemoryMapLib/MemoryMapLib.c` still carries sheng's SM8550 map. It must
  be rewritten from this device's DTB (29 base regions plus the six labelled
  overlay regions: `HLOS1`, `PIL_Reserved`, `Display_Demura`, `DXE_Heap`,
  `DBI_Dump`, `DXE_Heap2`). Booting with the wrong map puts UEFI allocations
  into reserved memory.
- `Library/ConfigurationMapLib` is likewise inherited.
- `Drivers/HongkongBootMemoryDxe`, `HongkongGopLogDxe`, `HongkongKeyInputDxe`
  and `HongkongDisplayDepexDxe` are sheng code with renamed symbols; the key
  input one in particular encodes sheng's SPMI key layout.
- `RAW.inc` still names sheng's N81A panel XML files. This device needs its own
  panel blobs before `USE_CUSTOM_DISPLAY_DRIVER` can ever be enabled.

## Boot path used for testing

`fastboot boot` with an Android boot image whose kernel field is
BootShim + the UEFI firmware volume, gzip compressed, DTB appended. No partition
is written, so a failed boot leaves the device recoverable by power cycling.
