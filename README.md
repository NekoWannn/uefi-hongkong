# uefi-hongkong

UEFI firmware for the Xiaomi 18 Pro (`hongkong`, SM8950 / `maili`), built as an overlay on [UniXNU/uefi-sheng](https://github.com/UniXNU/uefi-sheng).

Extracted firmware facts: see the XNU repo docs (docs/hongkong-firmware.md).

- FD base `0xC6800000`, size `0x369000` (from the stock `uefi_a` ELF64 header)
- Panel 1120x2436, framebuffer `0xF8C60000` + `0x2B00000`

