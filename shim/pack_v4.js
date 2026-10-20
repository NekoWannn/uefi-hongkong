// Pack a raw aarch64 payload (+optional ramdisk) into a boot image.
//   node pack_v4.js CODE OUT [--nohdr] [--ramdisk FILE] [--v2]
// --nohdr : payload already has its own arm64 Image header
// --v2    : emit header_version 2 (kernel @0x8000, ramdisk @0x1000000) like the
//           stock PixelOS / ios-sweet images; v4 puts the ramdisk in vendor_boot
//           so ABL ignores the one we embed here.
const fs = require("fs");

const args = process.argv.slice(2);
const noHdr = args.includes("--nohdr");
const v2 = args.includes("--v2");
const ri = args.indexOf("--ramdisk");
const ramdiskPath = ri >= 0 ? args[ri + 1] : null;
const [src, dst] = args.filter((a, i) => !a.startsWith("--") && !(ri >= 0 && i === ri + 1));
const code = fs.readFileSync(src);
const ramdisk = ramdiskPath ? fs.readFileSync(ramdiskPath) : Buffer.alloc(0);

const ARM64_MAGIC = 0x644d5241;
const PAGE = 4096;
const HDR = 1584;

const pad = (b) => (b.length % PAGE === 0 ? b : Buffer.concat([b, Buffer.alloc(PAGE - (b.length % PAGE))]));

function wrap(c) {
  const h = Buffer.alloc(64);
  h.writeUInt32LE(0x14000010, 0);
  h.writeBigUInt64LE(0n, 8);
  h.writeBigUInt64LE(BigInt(64 + c.length), 16);
  h.writeBigUInt64LE(0n, 24);
  h.writeUInt32LE(ARM64_MAGIC, 56);
  return Buffer.concat([h, c]);
}

const kernel = noHdr ? code : wrap(code);

function headerV2(kernelSize, ramdiskSize) {
  // struct boot_img_hdr_v2 is 1660 bytes; the page-sized buffer holds it and
  // the padding ABL expects before the kernel.
  const h = Buffer.alloc(PAGE);
  h.write("ANDROID!", 0, "binary");
  h.writeUInt32LE(kernelSize, 8);
  h.writeUInt32LE(0x8000, 12);          // kernel_addr
  h.writeUInt32LE(ramdiskSize, 16);
  h.writeUInt32LE(0x1000000, 20);       // ramdisk_addr
  h.writeUInt32LE(0, 24);               // second_size
  h.writeUInt32LE(0, 28);
  h.writeUInt32LE(0x100, 32);           // tags_addr
  h.writeUInt32LE(PAGE, 36);            // page_size
  h.writeUInt32LE(2, 40);               // header_version
  // os_version 17.0.0 + patch level 2035-06, packed as mkbootimg does
  h.writeUInt32LE(((((17 << 14) | (0 << 7) | 0) << 11) | ((35 << 4) | 6)) >>> 0, 44);
  h.write("pebble", 48, "binary");       // name
  h.write("console=null", 64, "binary"); // cmdline
  h.writeUInt32LE(0, 1632);              // recovery_dtbo_size
  h.writeBigUInt64LE(0n, 1636);          // recovery_dtbo_offset
  h.writeUInt32LE(1660, 1640);           // header_size
  h.writeUInt32LE(0, 1648);              // dtb_size
  h.writeBigUInt64LE(0n, 1652);          // dtb_addr
  return h;
}

function headerV4(kernelSize, ramdiskSize) {
  const h = Buffer.alloc(HDR);
  h.write("ANDROID!", 0, "binary");
  h.writeUInt32LE(kernelSize, 8);
  h.writeUInt32LE(ramdiskSize, 12);
  h.writeUInt32LE(0, 16);
  h.writeUInt32LE(HDR, 20);
  h.writeUInt32LE(4, 40);
  h.writeUInt32LE(0, 1580);
  return h;
}

const hdr = v2 ? headerV2(kernel.length, ramdisk.length) : headerV4(kernel.length, ramdisk.length);
const parts = [pad(hdr)];

parts.push(pad(kernel));

if (ramdisk.length) parts.push(pad(ramdisk));

const img = Buffer.concat(parts);
fs.writeFileSync(dst, img);
console.log(
  `wrote ${dst}: v${v2 ? 2 : 4} code=${code.length} kernel=${kernel.length} ` +
    `ramdisk=${ramdisk.length} total=${img.length} header=${noHdr ? "kept" : "added"}`
);
