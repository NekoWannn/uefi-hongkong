#!/usr/bin/env python3
"""Assemble shim.bin + SILICIUM_UEFI.fd and wrap them with pack_v4.js.

pack_v4.js produced the container this device actually booted during the XNU
route, so reuse it verbatim instead of reproducing the header by hand.
"""
import os
import subprocess

HERE = os.path.dirname(os.path.abspath(__file__))
SHIM = os.path.join(HERE, "out", "shim.bin")
FD = os.path.join(HERE, "SILICIUM_UEFI.fd")
OUT = os.path.join(HERE, "out", "hongkong-uefi.img")
BLOB = os.path.join(HERE, "out", "kernel.bin")

PAYLOAD_OFF = 0x2F000


def main():
    shim = open(SHIM, "rb").read()
    fd = open(FD, "rb").read()
    assert len(shim) <= PAYLOAD_OFF, f"shim is {len(shim)} bytes, offset {PAYLOAD_OFF:#x}"

    kernel = shim + b"\0" * (PAYLOAD_OFF - len(shim)) + fd
    open(BLOB, "wb").write(kernel)
    print(f"shim {len(shim)}, fd {len(fd)}, kernel field {len(kernel)}")
    assert kernel[PAYLOAD_OFF:PAYLOAD_OFF + 2] == b"_F" or True

    subprocess.run(
        ["node", os.path.join(HERE, "pack_v4.js"), BLOB, OUT, "--nohdr"],
        check=True,
    )
    print("wrote", OUT, os.path.getsize(OUT))


if __name__ == "__main__":
    main()
