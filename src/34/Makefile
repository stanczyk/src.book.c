#
# Makefile
# Copyright (c) 2022-2023 Jarosław Stańczyk <jaroslaw@stanczyk.pro>
#
TOOLS := ../make
include $(TOOLS)/make1b.mk
include $(TOOLS)/make_c1.mk
CLEAN_C += $(shell find . -type f -name "*.txt")

.PHONY: all
all: 	prg34-00 \
		prg34-01 prg34-02 prg34-03 prg34-04 prg34-05 prg34-06 prg34-07 prg34-08 prg34-09 prg34-10 \
		prg34-11 prg34-12 prg34-13 prg34-14

prg34-00: prg34-00.c
prg34-01: prg34-01.c
prg34-02: prg34-02.c
prg34-03: prg34-03.c
prg34-04: prg34-04.c
prg34-05: prg34-05.c
prg34-06: prg34-06.c
prg34-07: prg34-07.c
prg34-08: prg34-08.c
# do uruchomienia przykładu prg34-09 potrzebna jest biblioteka libdfp -> patrz Makefile do prg04-13
prg34-09: LDLIBS += -ldfp
prg34-09: prg34-09.c
prg34-10: prg34-10.c
prg34-11: prg34-11.c
prg34-12: prg34-12.c
prg34-13: prg34-13.c
prg34-14: prg34-14.c


include $(TOOLS)/make_c2.mk
include $(TOOLS)/make_clean.mk
# eof.