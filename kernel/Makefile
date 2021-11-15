LDS = kernel.ld
CC = gcc
LD = ld

CFLAGS = -ffreestanding -fshort-wchar -Isrc -ggdb -O0 -Wall -Wextra
LDFLAGS = -T $(LDS) -static -Bsymbolic -nostdlib

SRCDIR := src
OBJDIR := obj
BUILDDIR = bin

rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

SRC = $(call rwildcard,$(SRCDIR),*.c)          
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))
DIRS = $(wildcard $(SRCDIR)/*)

setup: 
	@mkdir -p $(BUILDDIR)
	@mkdir -p $(OBJDIR)

build: $(OBJS) link

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $^ -o $@
	
link:
	$(LD) $(LDFLAGS) -o $(BUILDDIR)/main.elf $(OBJS)

clean:
	@rm -rf $(BUILDDIR)
	@rm -rf $(OBJDIR)