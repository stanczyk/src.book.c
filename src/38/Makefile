#
# Makefile
# Copyright (c) 2022-2023 Jarosław Stańczyk <jaroslaw@stanczyk.pro>
#
TOOLS := ../make
include $(TOOLS)/make1b.mk
include $(TOOLS)/make_c1.mk

.PHONY: all
all: 	prg38-00 \
		prg38-01

prg38-00: prg38-00.c
prg38-01: LDLIBS += -lm
prg38-01: prg38-01.c

include $(TOOLS)/make_c2.mk
include $(TOOLS)/make_clean.mk
# eof.