SRCDIR = .
EFIDIR = ../gnu-efi
VPATH = $(SRCDIR)
include $(EFIDIR)/Make.defaults

CPPFLAGS	+= -D__KERNEL__ -I/usr/src/sys/build/include
CRTOBJS		= $(EFIDIR)/gnuefi/crt0-efi-$(ARCH).o
LDSCRIPT	= $(EFIDIR)/gnuefi/elf_$(ARCH)_efi.lds
LDFLAGS		+= -shared -Bsymbolic -L$(EFIDIR)/lib -L$(EFIDIR)/gnuefi $(CRTOBJS)
LOADLIBES	+= -lefi -lgnuefi
LOADLIBES	+= $(LIBGCC)
LOADLIBES	+= -T $(LDSCRIPT)
TARGET_APPS = main.efi
INCDIR = -I$(EFIDIR) -I$(EFIDIR)/inc -I$(EFIDIR)/inc/$(ARCH) \
	 -I$(EFIDIR)/inc/protocol

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

include $(EFIDIR)/Make.rules
