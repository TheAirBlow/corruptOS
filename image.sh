mkdir -p $1
rm -rf $1/$2.img
# Create image
dd if=/dev/zero bs=1M count=0 seek=64 of=$1/$2.img
parted -s $1/$2.img mklabel gpt
parted -s $1/$2.img mkpart ESP fat32 2048s 100%
parted -s $1/$2.img set 1 esp on
cd limine && ./limine-install ../$1/$2.img
cd ..
# Mount image
USED_LOOPBACK=$(losetup -Pf --show $1/$2.img)
# Format ESP
mkfs.fat -F 32 ${USED_LOOPBACK}p1
# Copy files
mkdir -p mount
mount ${USED_LOOPBACK}p1 mount
mkdir -p mount/EFI/BOOT
cp -v kernel/bin/kernel.elf kernel/limine.cfg limine/limine.sys ovmf/startup.nsh mount/
cp -v limine/BOOTX64.EFI mount/efi/boot/bootx64.efi
# Unmount
sync
umount mount
losetup -d ${USED_LOOPBACK}