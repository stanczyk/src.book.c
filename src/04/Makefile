#
# Makefile
# Copyright (c) 2022-2024 Jarosław Stańczyk <jaroslaw@stanczyk.pro>
#
TOOLS := ../make
include $(TOOLS)/make1b.mk
include $(TOOLS)/make_c1.mk

.PHONY: all
all: prg04-00 \
	 prg04-01 prg04-02 prg04-03 prg04-04 prg04-05 prg04-06 prg04-07 prg04-08 prg04-09 prg04-10 \
	 prg04-11 prg04-12 prg04-13 prg04-14
prg04-00: prg04-00.c
prg04-01: prg04-01.c
prg04-02: prg04-02.c
prg04-03: prg04-03.c
prg04-04: prg04-04.c
prg04-05: prg04-05.c
prg04-06: prg04-06.c
# prg04-07
# do kompilacji przykładu użyto kompilatora clang w wersji 14.0.0
# ponieważ gcc nie wspiera tej funkcjonalności - szczegóły w prg04-07.c
prg04-07: CC=clang
prg04-07: CFLAGS = $(CLFLAGS)
prg04-07: CFLAGS += -Wno-pre-c2x-compat
prg04-07: prg04-07.c
prg04-08: prg04-08.c
prg04-09: prg04-09.c
prg04-10: prg04-10.c
prg04-11: prg04-11.c
prg04-12: prg04-12.c
# prg04-13
# do uruchomienia przykładu prg04-13 potrzebna jest biblioteka libdfp
# ponieważ standardowa biblioteka c - glibc nie wspiera tej funkcjonalności - szczegóły w prg04-13.c
# 	pakiet dla Ubuntu: libdfp-dev
# 		sudo apt-get install -y libdfp-dev
# 	lub źródła: https://github.com/libdfp/libdfp
# 		kompilacja i instalacja: configure; make; sudo make install
prg04-13: LDLIBS += -ldfp
prg04-13: prg04-13.c
prg04-14: prg04-14.c

include $(TOOLS)/make_c2.mk
include $(TOOLS)/make_clean.mk
# eof.