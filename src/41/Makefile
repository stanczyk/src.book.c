#
# Makefile
# Copyright (c) 2022-2024 Jarosław Stańczyk <jaroslaw@stanczyk.pro>
#
TOOLS := ../make
include $(TOOLS)/make1b.mk
include $(TOOLS)/make_c1.mk

.PHONY: all
all: prg41-00 prg41-01 prg41-02
prg41-00: prg41-00.c
prg41-01: prg41-01.c
prg41-02: prg41-02.c

include $(TOOLS)/make_c2.mk
include $(TOOLS)/make_clean.mk
# eof.