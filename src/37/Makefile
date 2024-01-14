#
# Makefile
# Copyright (c) 2022-2024 Jarosław Stańczyk <jaroslaw@stanczyk.pro>
#
TOOLS := ../make
include $(TOOLS)/make1b.mk
include $(TOOLS)/make_c1.mk

.PHONY: all
all: prg37-00 \
	 prg37-01 prg37-02 prg37-03 prg37-04 prg37-05 prg37-06 prg37-07 prg37-08 prg37-09 prg37-10 \
	 prg37-11 prg37-12 prg37-13 prg37-14
prg37-00: prg37-00.c
prg37-01: prg37-01.c
prg37-02: LDLIBS += -lsafec
prg37-02: prg37-02.c
prg37-03: prg37-03.c
prg37-04: prg37-04.c
prg37-05: prg37-05.c
prg37-06: LDLIBS += -lsafec
prg37-06: prg37-06.c
prg37-07: prg37-07.c
prg37-08: prg37-08.c
prg37-09: prg37-09.c
prg37-10: prg37-10.c
prg37-11: prg37-11.c
prg37-12: LDLIBS += -lsafec
prg37-12: prg37-12.c
prg37-13: prg37-13.c
prg37-14: prg37-14.c

include $(TOOLS)/make_c2.mk
include $(TOOLS)/make_clean.mk
# eof.