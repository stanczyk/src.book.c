#
# Makefile
# Copyright (c) 2022-2023 Jarosław Stańczyk <jaroslaw@stanczyk.pro>
#
TOOLS := ../make
include $(TOOLS)/make1b.mk
include $(TOOLS)/make_c1.mk

.PHONY: all
all:	prg35-00 \
		prg35-01 prg35-02 prg35-03 prg35-04 prg35-05 prg35-06 prg35-07 prg35-08 prg35-09 prg35-10 \
		prg35-11 prg35-12 prg35-13 prg35-14 prg35-15

prg35-00: prg35-00.c
prg35-01: prg35-01.c
prg35-02: prg35-02.c
prg35-03: prg35-03.c
prg35-04: prg35-04.c
prg35-05: prg35-05.c
prg35-06: prg35-06.c
prg35-07: prg35-07.c
prg35-08: prg35-08.c
prg35-09: prg35-09.c
prg35-10: prg35-10.c
prg35-11: prg35-11.c
prg35-12: prg35-12.c
prg35-13: prg35-13.c
prg35-14: prg35-14.c
prg35-15: prg35-15.c
prg35-16: LDLIBS += -lsafec
prg35-16: prg35-16.c

include $(TOOLS)/make_c2.mk
include $(TOOLS)/make_clean.mk
# eof.