VERSION = 3.0.12

MKFILE_PATH := $(abspath $(lastword $(MAKEFILE_LIST)))
SRCDIR = $(dir $(MKFILE_PATH))

VPATH = $(SRCDIR)

all:
	cd gnuefi && make
	cd lib && make

.PHONY: depend