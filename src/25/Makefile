#
# Makefile
# Copyright (c) 2022-2024 Jarosław Stańczyk <jaroslaw@stanczyk.pro>
#
TOOLS := ../make
include $(TOOLS)/make1b.mk
include $(TOOLS)/make_c1.mk

.PHONY: all
all: prg25-01 prg25-02
prg25-01: prg25-01.c
prg25-02: prg25-02.c

include $(TOOLS)/make_c2.mk
include $(TOOLS)/make_clean.mk
# eof.