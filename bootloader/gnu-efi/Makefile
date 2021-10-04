VERSION = 3.0.12

MKFILE_PATH := $(abspath $(lastword $(MAKEFILE_LIST)))
SRCDIR = $(dir $(MKFILE_PATH))

VPATH = $(SRCDIR)

include $(SRCDIR)/Make.defaults

all:
	cd gnuefi && make
	cd apps && make
	cd lib && make

.PHONY: depend

include $(SRCDIR)/Make.rules
