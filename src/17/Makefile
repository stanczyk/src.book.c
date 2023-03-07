#
# Makefile
# Copyright (c) 2022-2023 Jarosław Stańczyk <jaroslaw@stanczyk.pro>
#
TOOLS := ../make
include $(TOOLS)/make1b.mk
include $(TOOLS)/make_c1.mk

.PHONY: all
all: 	prg17-00 \
		prg17-01 prg17-02 prg17-03 prg17-04 prg17-05

prg17-00: prg17-00.c
prg17-01: LDLIBS += -lm
prg17-01: prg17-01.c
prg17-02: LDLIBS += -lm
prg17-02: prg17-02.c prg17-00.h
prg17-03: LDLIBS += -lm
prg17-03: prg17-03.c
prg17-04: LDLIBS += -lm
prg17-04: prg17-04.c
prg17-05: LDLIBS += -lm
prg17-05: prg17-05.c prg17-00.h
# prg17-06 - 	 # fragment kodu

include $(TOOLS)/make_c2.mk
include $(TOOLS)/make_clean.mk
# eof.