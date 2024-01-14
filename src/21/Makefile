#
# Makefile
# Copyright (c) 2022-2024 Jarosław Stańczyk <jaroslaw@stanczyk.pro>
#
TOOLS := ../make
include $(TOOLS)/make1b.mk
include $(TOOLS)/make_c1.mk

.PHONY: all
all: prg21-00 prg21-01
prg21-00: prg21-00.c
# prg21-01 kompilacja powoduje błąd dla gcc 12 i 13 (13.1.0 i 13.2.0) - brak wsparcia dla wybranych funkcjonalności
prg21-01: CC = clang
prg21-01: CFLAGS = $(CLFLAGS)
prg21-01: prg21-01.c

include $(TOOLS)/make_c2.mk
include $(TOOLS)/make_clean.mk
# eof.