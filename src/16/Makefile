#
# Makefile
# Copyright (c) 2022-2024 Jarosław Stańczyk <jaroslaw@stanczyk.pro>
#
TOOLS := ../make
include $(TOOLS)/make1b.mk
include $(TOOLS)/make_c1.mk

.PHONY: all
all: prg16-00          prg16-02
prg16-00: prg16-00.c
prg16-01: prg16-01.c 	# kompilacja powiedzie się tylko wówczas, gdy jest wsparcie dla rozszerzeń bibliotecznych
						# czyli __STDC_LIB_EXT1__ jest zdefiniowane
prg16-02: LDLIBS += -lm
prg16-02: prg16-02.c

include $(TOOLS)/make_c2.mk
include $(TOOLS)/make_clean.mk
# eof.