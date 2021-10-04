SRCDIR = .
VPATH = $(SRCDIR)
include $(SRCDIR)/gnu-efi/Make.defaults

CPPFLAGS	+= -D__KERNEL__ -I/usr/src/sys/build/include
CRTOBJS		= gnu-efi/x86_64/gnuefi/crt0-efi-$(ARCH).o
LDSCRIPT	= gnu-efi/gnuefi/elf_$(ARCH)_efi.lds
LDFLAGS		+= -shared -Bsymbolic -L./gnu-efi/lib -L./gnu-efi/gnuefi $(CRTOBJS)
LOADLIBES	+= -lefi -lgnuefi
LOADLIBES	+= $(LIBGCC)
LOADLIBES	+= -T $(LDSCRIPT)
TARGET_APPS = main.efi
INCDIR = -I$(SRCDIR)/gnu-efi -I$(TOPDIR)/gnu-efi/inc -I$(TOPDIR)/gnu-efi/inc/$(ARCH) \
	 -I$(TOPDIR)/gnu-efi/inc/protocol

ifneq ($(HAVE_EFI_OBJCOPY),)
FORMAT		:= --target efi-app-$(ARCH)
$(TARGET_BSDRIVERS): FORMAT=--target efi-bsdrv-$(ARCH)
$(TARGET_RTDRIVERS): FORMAT=--target efi-rtdrv-$(ARCH)
else
SUBSYSTEM	:= 0xa
$(TARGET_BSDRIVERS): SUBSYSTEM = 0xb
$(TARGET_RTDRIVERS): SUBSYSTEM = 0xc
FORMAT		:= -O binary
LDFLAGS		+= --defsym=EFI_SUBSYSTEM=$(SUBSYSTEM)
endif

TARGETS = $(TARGET_APPS) $(TARGET_BSDRIVERS) $(TARGET_RTDRIVERS)
CFLAGS += -Wno-error=unused-parameter -Wno-error=unused-variable

all:	$(TARGETS)
clean:
	rm -f $(TARGETS) *~ *.o *.so
.PHONY: install

include $(SRCDIR)/gnu-efi/Make.rules
