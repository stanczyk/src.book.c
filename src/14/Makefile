#
# Makefile
# Copyright (c) 2022-2024 Jarosław Stańczyk <jaroslaw@stanczyk.pro>
#
TOOLS := ../make
include $(TOOLS)/make1b.mk
include $(TOOLS)/make_c1.mk

.PHONY: all
all: prg14-00 prg14-01 prg14-02 prg14-03 prg14-04 prg14-05
prg14-00: prg14-00.c
prg14-01: prg14-01.c
prg14-02: prg14-02.c
prg14-03: prg14-03.c
prg14-04: LDLIBS += -lm
prg14-04: prg14-04.c
prg14-05: CC = clang
prg14-05: CFLAGS = $(CLFLAGS)
prg14-05: LDLIBS += -lm
prg14-05: prg14-05.c

include $(TOOLS)/make_c2.mk
include $(TOOLS)/make_clean.mk
# eof.