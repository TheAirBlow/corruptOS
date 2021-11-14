OSNAME = corruptOS

GNUEFI = ../bootloader
OVMFDIR = ../ovmf
LDS = kernel.ld
CC = gcc
LD = ld

CFLAGS = -ffreestanding -fshort-wchar -Isrc
LDFLAGS = -T $(LDS) -static -Bsymbolic -nostdlib

SRCDIR := src
OBJDIR := obj
BUILDDIR = bin
FILESDIR = files
BOOTEFI := $(GNUEFI)/main.efi

rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

SRC = $(call rwildcard,$(SRCDIR),*.c)          
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))
DIRS = $(wildcard $(SRCDIR)/*)

kernel: $(OBJS) link

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $^ -o $@
	
link:
	$(LD) $(LDFLAGS) -o $(BUILDDIR)/kernel.elf $(OBJS)

setup:
	@mkdir -p $(BUILDDIR)
	@mkdir -p $(OBJDIR)

clean:
	@rm -rf $(BUILDDIR)
	@rm -rf $(OBJDIR)

buildimg:
	dd if=/dev/zero of=$(BUILDDIR)/$(OSNAME).img bs=512 count=230000
	mkfs.vfat -F 32 $(BUILDDIR)/$(OSNAME).img
	mmd -i $(BUILDDIR)/$(OSNAME).img ::/efi
	mmd -i $(BUILDDIR)/$(OSNAME).img ::/efi/boot
	mmd -i $(BUILDDIR)/$(OSNAME).img ::/kernel
	mmd -i $(BUILDDIR)/$(OSNAME).img ::/files
	mcopy -i $(BUILDDIR)/$(OSNAME).img $(BOOTEFI) ::/efi/boot
	mcopy -i $(BUILDDIR)/$(OSNAME).img startup.nsh ::
	mcopy -i $(BUILDDIR)/$(OSNAME).img $(BUILDDIR)/kernel.elf ::/kernel
	mcopy -i $(BUILDDIR)/$(OSNAME).img $(FILESDIR)/zap-light16.psf ::/files

run:
	qemu-system-x86_64 -drive file=$(BUILDDIR)/$(OSNAME).img -m 1024M -cpu qemu64 -drive if=pflash,format=raw,unit=0,file="$(OVMFDIR)/OVMF_CODE-pure-efi.fd",readonly=on -drive if=pflash,format=raw,unit=1,file="$(OVMFDIR)/OVMF_VARS-pure-efi.fd" -net nic
