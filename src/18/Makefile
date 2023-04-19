#
# Makefile
# Copyright (c) 2022-2023 Jarosław Stańczyk <jaroslaw@stanczyk.pro>
#
TOOLS := ../make
include $(TOOLS)/make1b.mk
include $(TOOLS)/make_c1.mk

.PHONY: all
all: 	prg18-00 \
		prg18-01 prg18-02

prg18-00: prg18-00.c
prg18-01: prg18-01.c
prg18-02: CFLAGS  = -std=c2x
prg18-02: CFLAGS += -Wall
prg18-02: CFLAGS += -Wextra
prg18-02: LDLIBS += -ldfp
prg18-02: prg18-02.c

include $(TOOLS)/make_c2.mk
include $(TOOLS)/make_clean.mk
# eof.