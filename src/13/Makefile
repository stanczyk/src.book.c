#
# Makefile
# Copyright (c) 2022-2023 Jarosław Stańczyk <jaroslaw@stanczyk.pro>
#
TOOLS := ../make
include $(TOOLS)/make1b.mk
include $(TOOLS)/make_c1.mk

.PHONY: all
all: prg13-01

# prg13-01: CFLAGS += -DNDEBUG
prg13-01: LDLIBS += -lm
prg13-01: prg13-01.c
prg13-02: prg13-02.c 	# zamierzony błąd kompilacji,
 						# chyba że program kompilowany jest w systemie, w którym sizeof(int) == 2

include $(TOOLS)/make_c2.mk
include $(TOOLS)/make_clean.mk
# eof.