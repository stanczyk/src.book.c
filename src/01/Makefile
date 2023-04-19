#
# Makefile
# Copyright (c) 2022-2023 Jarosław Stańczyk <jaroslaw@stanczyk.pro>
#
TOOLS := ../make
include $(TOOLS)/make1b.mk
include $(TOOLS)/make_c1.mk
DONT_INDENT += prg01-02.c

.PHONY: all
all: prg01-01 prg01-02

prg01-01: prg01-01.c
prg01-02: prg01-02.c

include $(TOOLS)/make_c2.mk
include $(TOOLS)/make_clean.mk
# eof.