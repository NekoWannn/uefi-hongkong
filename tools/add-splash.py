#!/usr/bin/env python3
"""Add the display splash reservation to the device DTB we append to boot.img.

ABL checks the appended DTB for the splash reservation before it hands over; if
the node is absent it powers the panel down, which makes a working UEFI look
like a black screen. The framebuffer address and size come from this device's
own memorymap (0xF8C60000, 0x2B00000).

Requires dtc on PATH (Ubuntu: apt install device-tree-compiler).
"""
import os
import re
import shutil
import subprocess
import sys

DTB = sys.argv[1] if len(sys.argv) > 1 else "Resources/DTBs/hongkong.dtb"
DTS = DTB + ".dts"

if not shutil.which("dtc"):
    sys.exit("dtc not found")

subprocess.run(["dtc", "-I", "dtb", "-O", "dts", "-o", DTS, DTB], check=True)
text = open(DTS, encoding="utf-8").read()

if "splash_region" in text:
    print("splash_region already present")
    sys.exit(0)

node = """
\tsplash_region: splash_region {
\t\treg = <0x0 0xF8C60000 0x0 0x02B00000>;
\t\tlabel = "cont_splash_region";
\t};
"""

# Insert before the final closing brace of the root node.
idx = text.rstrip().rfind("};")
if idx < 0:
    sys.exit("cannot find the root terminator")
text = text[:idx] + node + text[idx:]
open(DTS, "w", encoding="utf-8").write(text)

subprocess.run(["dtc", "-I", "dts", "-O", "dtb", "-o", DTB, DTS], check=True)
os.remove(DTS)
print(f"splash_region added to {DTB}")
