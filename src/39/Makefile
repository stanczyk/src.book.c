#
# Makefile
# Copyright (c) 2022-2023 Jarosław Stańczyk <jaroslaw@stanczyk.pro>
#
TOOLS := ../make
include $(TOOLS)/make1b.mk
include $(TOOLS)/make_c1.mk

.PHONY: all
all: 	prg39-00 \
		prg39-01 prg39-02 prg39-03 prg39-04 prg39-05 prg39-06

prg39-00: prg39-00.c
# prg39-01: CFLAGS += -DNUM_THREADS=10
prg39-01: CFLAGS += -pthread
prg39-01: prg39-01.c
# prg39-02: CFLAGS += -DNUM_THREADS=10
prg39-02: CFLAGS += -pthread
prg39-02: prg39-02.c
# prg39-03: CFLAGS += -DNUM_THREADS=10
prg39-03: CFLAGS += -pthread
prg39-03: prg39-03.c
# prg39-04: CFLAGS += -DNUM_THREADS=10
prg39-04: CFLAGS += -pthread
prg39-04: prg39-04.c
# prg39-05: CFLAGS += -DNUM_THREADS=10
prg39-05: CFLAGS += -pthread
prg39-05: prg39-05.c
# prg39-06: CFLAGS += -DNUM_THREADS=10
prg39-06: CFLAGS += -pthread
prg39-06: prg39-06.c

include $(TOOLS)/make_c2.mk
include $(TOOLS)/make_clean.mk
# eof.