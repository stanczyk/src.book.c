#
# Makefile
# Copyright (c) 2022-2024 Jarosław Stańczyk <jaroslaw@stanczyk.pro>
#
TOOLS := ../make
include $(TOOLS)/make1b.mk
include $(TOOLS)/make_c1.mk

.PHONY: all
all: prg11-01 prg11-02 prg11-03 prg11-04 \
	          prg11-12 prg11-13 prg11-14 prg11-15 prg11-16          prg11-18 prg11-19 \
	 prg11-21                   prg11-24 prg11-25
prg11-01: prg11-01.c
prg11-02: prg11-02.c prj_head.h
prg11-03: CFLAGS += -D WERSJA=1
prg11-03: prg11-03.c wersja-1.h wersja-2.h
prg11-04: prg11-04.c wersja-1.h wersja-2.h
# prg11-05 -- prg11-11 - kompilacja powoduje błędy
# brak wsparcia w gcc 12 i 13 (13.1.0, 13.2.0) dla nowych funkcjonalności
prg11-05: prg11-05.c  # błąd kompilacji - brak wsparcia dla #embed
prg11-06: prg11-06.c  # błąd kompilacji - brak wsparcia dla #embed
prg11-07: prg11-07.c  # błąd kompilacji - brak wsparcia dla #embed
prg11-08: prg11-08.c  # błąd kompilacji - brak wsparcia dla #embed
prg11-09: prg11-09.c  # błąd kompilacji - brak wsparcia dla #embed, fragment programu
prg11-10: prg11-10.c  # błąd kompilacji - brak wsparcia dla #embed, fragment programu
prg11-11: prg11-11.c  # błąd kompilacji - brak wsparcia dla __has_embed()
prg11-12: prg11-12.c
prg11-13: prg11-13.c
prg11-14: prg11-14.c
prg11-15: prg11-15.c
prg11-16: prg11-16.c
# prg11-17 			  # fragment kodu
prg11-18: CFLAGS += -DINSTRUKCJA=2
prg11-18: prg11-18.c
prg11-19: CFLAGS += -D DEBUG
prg11-19: prg11-19.c
# prg11-20 			  # brak przykładu
prg11-21: CFLAGS += -D DEBUG
prg11-21: prg11-21.c
prg11-22: prg11-22.c  # zamierzony błąd kompilacji, demonstruje działanie dyrektywy #line
prg11-23: prg11-23.c  # zamierzony błąd kompilacji, demonstruje działanie dyrektywy #error
prg11-24: prg11-24.c
prg11-25: prg11-25.c

include $(TOOLS)/make_c2.mk
include $(TOOLS)/make_clean.mk
# eof.