#
# Makefile
# Copyright (c) 2022-2024 Jarosław Stańczyk <jaroslaw@stanczyk.pro>
#
TOOLS := ../make
include $(TOOLS)/make1b.mk
include $(TOOLS)/make_c1.mk

.PHONY: all
all: prg06-01 prg06-02 prg06-03 prg06-04 prg06-05          prg06-07          prg06-09 prg06-10 \
	 prg06-11                            prg06-15 prg06-16 prg06-17 prg06-18 prg06-19 prg06-20 \
	 prg06-21 prg06-22 prg06-23 prg06-24          prg06-26 prg06-27 prg06-28 prg06-29 prg06-30
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	$(CC) -MM $(CFLAGS) $*.c > $*.d
prg06-01: prg06-01.c
prg06-02: prg06-02.c
prg06-03: prg06-03.c
prg06-04: prg06-04.c
prg06-05a.o: prg06-05a.c
prg06-05b.o: prg06-05b.c
prg06-05: prg06-05a.o prg06-05b.o
	$(CC) -o $@ $^
prg06-06: prg06-06.c  # zamierzony błąd kompilacji
prg06-07: prg06-07.c
prg06-08a.o: prg06-08a.c
prg06-08a.o: prg06-08b.h
prg06-08b.o: prg06-08b.c
prg06-08b.o: prg06-08b.h
prg06-08: prg06-08a.o prg06-08b.o
	$(CC) -o $@ $^
# prg06-09: CFLAGS += -DNUM_THREADS=9
prg06-09: CFLAGS += -pthread
prg06-09: prg06-09.c
# prg06-10:
# - gcc 11 i 12 powodują błąd kompilacji (brak wsparcia dla specyfikatora constexpr)
# - gcc 13 działa poprawnie
prg06-10: prg06-10.c
prg06-11: prg06-11.c
prg06-12: prg06-12.c  # zamierzony błąd kompilacji
prg06-13: prg06-13.c  # zamierzony błąd kompilacji
prg06-14: prg06-14.c  # zamierzony błąd kompilacji
prg06-15: prg06-15.c
prg06-16: prg06-16.c
prg06-17: CFLAGS += -DNUM_THREADS=10000
prg06-17: CFLAGS += -pthread
prg06-17: prg06-17.c
prg06-18: prg06-18.c
prg06-19: prg06-19.c
prg06-20: prg06-20.c
prg06-21: prg06-21.c
prg06-22: prg06-22.c
prg06-23: prg06-23.c
prg06-24: prg06-24.c
prg06-25: prg06-25.c  # zamierzony błąd kompilacji
prg06-26: prg06-26.c
prg06-27: prg06-27.c
prg06-28: prg06-28.c
prg06-29: prg06-29.c
prg06-30: prg06-30.c

include $(TOOLS)/make_c2.mk
include $(TOOLS)/make_clean.mk
# eof.