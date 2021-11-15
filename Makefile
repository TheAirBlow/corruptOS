BUILDDIR = bin
OSNAME = corruptOS
OVMFDIR = ovmf

all: boot main image run
nodbg: boot main image run-nodbg
norun: boot main image

boot:
	make -C ./gnu-efi
	make -C ./gnu-efi/gnuefi
	make -C ./gnu-efi/inc
	make -C ./gnu-efi/lib
	make -C ./bootloader

main: 
	make -C ./kernel setup
	make -C ./kernel build

image:
	@mkdir -p $(BUILDDIR)
	@rm -rf $(BUILDDIR)/$(OSNAME).img.part
	# Create image
	dd if=/dev/zero of=$(BUILDDIR)/$(OSNAME).img.part bs=512 count=230000
	mkfs.vfat -F 32 $(BUILDDIR)/$(OSNAME).img.part
	# Directories
	mmd -i $(BUILDDIR)/$(OSNAME).img.part ::/efi
	mmd -i $(BUILDDIR)/$(OSNAME).img.part ::/efi/boot
	mmd -i $(BUILDDIR)/$(OSNAME).img.part ::/kernel
	mmd -i $(BUILDDIR)/$(OSNAME).img.part ::/files
	# Copy files
	mcopy -i $(BUILDDIR)/$(OSNAME).img.part bootloader/startup.nsh ::
	mcopy -i $(BUILDDIR)/$(OSNAME).img.part bootloader/main.efi ::/efi/boot
	mcopy -i $(BUILDDIR)/$(OSNAME).img.part files/main.psf ::/files
	mcopy -i $(BUILDDIR)/$(OSNAME).img.part kernel/bin/main.elf ::/kernel
	# Rename file
	mv $(BUILDDIR)/$(OSNAME).img.part $(BUILDDIR)/$(OSNAME).img

run:
	qemu-system-x86_64 -s -S -drive file=$(BUILDDIR)/$(OSNAME).img,format=raw -m 1024M -cpu qemu64 -drive if=pflash,format=raw,unit=0,file="$(OVMFDIR)/OVMF_CODE-pure-efi.fd",readonly=on -drive if=pflash,format=raw,unit=1,file="$(OVMFDIR)/OVMF_VARS-pure-efi.fd" -net nic

run-nogdb:
	qemu-system-x86_64 -drive file=$(BUILDDIR)/$(OSNAME).img,format=raw -m 1024M -cpu qemu64 -drive if=pflash,format=raw,unit=0,file="$(OVMFDIR)/OVMF_CODE-pure-efi.fd",readonly=on -drive if=pflash,format=raw,unit=1,file="$(OVMFDIR)/OVMF_VARS-pure-efi.fd" -net nic