#
# Makefile
# Copyright (c) 2022-2024 Jarosław Stańczyk <jaroslaw@stanczyk.pro>
#
TOOLS := ../make
include $(TOOLS)/make1b.mk
include $(TOOLS)/make_c1.mk

.PHONY: all
all: prg23-00 \
	 prg23-01 prg23-02 prg23-03 prg23-04
prg23-00: prg23-00.c
prg23-01: LDLIBS += -lm
prg23-01: prg23-01.c
prg23-02: LDLIBS += -lm
prg23-02: prg23-02.c
prg23-03: LDLIBS += -lm
prg23-03: prg23-03.c
# prg23-04 dla gcc 12 i 13 (13.1.0 i 13.2.0) podczas kompilacji pojawia się ostrzeżenie o ignorowaniu zastosowanej pragmy
# tzn. brak wsparcia dla tej funkcjonalności
prg23-04: CC = clang
prg23-04: CFLAGS = $(CLFLAGS)
prg23-04: LDLIBS += -lm
prg23-04: prg23-04.c

include $(TOOLS)/make_c2.mk
include $(TOOLS)/make_clean.mk
# eof.