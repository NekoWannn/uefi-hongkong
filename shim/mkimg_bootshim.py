#!/usr/bin/env python3
"""Wrap the firmware volume with upstream's BootShim.

BootShim expects the volume immediately after itself: its header records
image_size = FD_SIZE + (_Payload - _Head), so the payload starts at the end of
the shim with no gap.
"""
import os
import subprocess

HERE = os.path.dirname(os.path.abspath(__file__))
SHIM = os.path.join(HERE, "BootShim.bin")
FD = os.path.join(HERE, "SILICIUM_UEFI.fd")
OUT = os.path.join(HERE, "out", "hongkong-uefi.img")
BLOB = os.path.join(HERE, "out", "kernel.bin")


def main():
    os.makedirs(os.path.join(HERE, "out"), exist_ok=True)
    shim = open(SHIM, "rb").read()
    fd = open(FD, "rb").read()
    if not (1024 <= len(shim) <= 4096):
        print(f"warning: BootShim is {len(shim)} bytes, expected a few hundred")

    blob = shim + fd
    open(BLOB, "wb").write(blob)
    print(f"BootShim {len(shim)}, FD {len(fd)}, kernel field {len(blob)}")

    subprocess.run(
        ["node", os.path.join(HERE, "pack_v4.js"), BLOB, OUT, "--nohdr"],
        check=True,
    )
    print("wrote", OUT, os.path.getsize(OUT))


if __name__ == "__main__":
    main()
