#
# Makefile
# Copyright (c) 2022-2024 Jarosław Stańczyk <jaroslaw@stanczyk.pro>
#
TOOLS := ../make
include $(TOOLS)/make1b.mk
include $(TOOLS)/make_c1.mk

.PHONY: all
all: prg10-01 prg10-02 prg10-03 prg10-04 prg10-05a prg10-05b prg10-06 prg10-07
prg10-01: prg10-01.c
prg10-02: prg10-02.c
prg10-03: prg10-03.c
prg10-04: prg10-04.c
prg10-05a: prg10-05a.c
prg10-05b: prg10-05b.h
prg10-05b: prg10-05b.c
prg10-06: prg10-06.c
prg10-07: prg10-07.c

include $(TOOLS)/make_c2.mk
include $(TOOLS)/make_clean.mk
# eof.