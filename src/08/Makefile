#
# Makefile
# Copyright (c) 2022-2023 Jarosław Stańczyk <jaroslaw@stanczyk.pro>
#
TOOLS := ../make
include $(TOOLS)/make1b.mk
include $(TOOLS)/make_c1.mk

.PHONY: all
all:	         prg08-02 prg08-03 prg08-04 prg08-05 prg08-05v2 prg08-06 prg08-07 prg08-08 prg08-09 prg08-10 \
		prg08-11 prg08-12 prg08-13 prg08-14 prg08-15 prg08-16 prg08-17 prg08-18 prg08-19 prg08-20 \
		prg08-21 prg08-22 prg08-23

# prg08-01 			  # brak przykładu
prg08-02: prg08-02.c
prg08-03: prg08-03.c
prg08-04: LDLIBS += -lm
prg08-04: prg08-04.c
prg08-05: prg08-05.c
# prg08-05v2, czyli prg08-05 podejście 2, kompilacja z flagą VER2
prg08-05v2: CFLAGS += -DVER2
prg08-05v2:
	$(CC) $(CFLAGS) prg08-05.c -o $@
prg08-06: prg08-06.c
prg08-07: prg08-07.c
prg08-08: prg08-08.c
prg08-09: prg08-09.c
prg08-10: prg08-10.c
prg08-11: prg08-11.c
prg08-12: prg08-12.c
prg08-13: prg08-13.c
prg08-14: prg08-14.c
prg08-15: prg08-15.c
prg08-16: prg08-16.c
prg08-17: prg08-17.c
prg08-18: prg08-18.c
prg08-19: prg08-19.c
prg08-20: prg08-20.c
prg08-21: prg08-21.c
prg08-22: prg08-22.c
prg08-23: prg08-23.c
prg08-24: prg08-24.c  # błąd kompilacji, operatory typowania jeszcze nie wspierane
prg08-25: prg08-25.c  # błąd kompilacji, operatory typowania jeszcze nie wspierane

include $(TOOLS)/make_c2.mk
include $(TOOLS)/make_clean.mk
# eof.