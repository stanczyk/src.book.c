#
# Makefile
# Copyright (c) 2022-2024 Jarosław Stańczyk <jaroslaw@stanczyk.pro>
#
TOOLS := ../make
include $(TOOLS)/make1b.mk
include $(TOOLS)/make_c1.mk

.PHONY: all
all: prg32-00 prg32-01 prg32-02 prg32-03 prg32-04          prg32-06 prg32-07
prg32-00: prg32-00.c
prg32-01: prg32-01.c
prg32-02: prg32-02.c
prg32-03: prg32-03.c
prg32-04: prg32-04.c
# prg32-05 		fragment kodu
prg32-06: prg32-06.c
prg32-07: prg32-07.c

include $(TOOLS)/make_c2.mk
include $(TOOLS)/make_clean.mk
# eof.