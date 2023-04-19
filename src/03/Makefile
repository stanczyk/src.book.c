#
# Makefile
# Copyright (c) 2022-2023 Jarosław Stańczyk <jaroslaw@stanczyk.pro>
#
TOOLS := ../make
include $(TOOLS)/make1b.mk
include $(TOOLS)/make_c1.mk

DONT_INDENT += prg03-01.c
DONT_INDENT += prg03-02.c
DONT_INDENT += prg03-03.c

.PHONY: all
all: prg03-01 prg03-02 prg03-03 prg03-04 prg03-05

prg03-01: prg03-01.c
prg03-02: prg03-02.c
prg03-02: CFLAGS += -Wno-trigraphs
prg03-02: CFLAGS += -trigraphs
prg03-03: prg03-03.c
prg03-04: prg03-04.c
prg03-05: prg03-05.c

include $(TOOLS)/make_c2.mk
include $(TOOLS)/make_clean.mk
# eof.