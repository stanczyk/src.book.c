#
# Makefile
# Copyright (c) 2022-2024 Jarosław Stańczyk <jaroslaw@stanczyk.pro>
#
TOOLS := ../make
include $(TOOLS)/make1b.mk
include $(TOOLS)/make_c1.mk

.PHONY: all
all: prg31-00 prg31-01
prg31-00: prg31-00.c
# prg31-01: CC = clang
prg31-01: prg31-01.c

include $(TOOLS)/make_c2.mk
include $(TOOLS)/make_clean.mk
# eof.