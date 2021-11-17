BUILDDIR = bin
OSNAME = corruptOS
OVMFDIR = ovmf

all: boot main image run
nogdb: boot main image run-nogdb
norun: boot main image

boot:
	make -C ./limine

main: 
	make -C ./kernel setup
	make -C ./kernel build

image:
	./image.sh ${BUILDDIR} ${OSNAME}

run:
	qemu-system-x86_64 -s -S -no-reboot -no-shutdown -drive file=$(BUILDDIR)/$(OSNAME).img,format=raw -m 1024M -cpu qemu64 -drive if=pflash,format=raw,unit=0,file="$(OVMFDIR)/OVMF_CODE-pure-efi.fd",readonly=on -drive if=pflash,format=raw,unit=1,file="$(OVMFDIR)/OVMF_VARS-pure-efi.fd" -net nic

run-nogdb:
	qemu-system-x86_64 -drive file=$(BUILDDIR)/$(OSNAME).img,format=raw -m 1024M -cpu qemu64 -drive if=pflash,format=raw,unit=0,file="$(OVMFDIR)/OVMF_CODE-pure-efi.fd",readonly=on -drive if=pflash,format=raw,unit=1,file="$(OVMFDIR)/OVMF_VARS-pure-efi.fd" -net nic