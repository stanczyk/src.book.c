#
# Makefile
# Copyright (c) 2022-2024 Jarosław Stańczyk <jaroslaw@stanczyk.pro>
#
TOOLS := ../make
include $(TOOLS)/make1b.mk
include $(TOOLS)/make_c1.mk

.PHONY: all
all: prg28-00 prg28-01 prg28-02
prg28-00: prg28-00.c
prg28-01: prg28-01.c
# prg28-02 gcc 12 i 13 (13.1.0, 13.2.0) brak wsparcia dla danej funkcjonalności
prg28-02: CC = clang
prg28-02: CFLAGS = $(CLFLAGS)
prg28-02: CFLAGS += -latomic
prg28-02: prg28-02.c

include $(TOOLS)/make_c2.mk
include $(TOOLS)/make_clean.mk
# eof.