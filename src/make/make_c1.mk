#
# make_c1.mk
# Copyright (c) 2023-2024 Jarosław Stańczyk <jaroslaw@stanczyk.pro>
#

# domyślny kompilator
CC = gcc

# opcje kompilatora
# gcc
CFLAGS := -std=c2x
CFLAGS += -Wpedantic
CFLAGS += -Wall
CFLAGS += -Wextra
# clang
CLFLAGS := -std=c2x
CLFLAGS += -Weverything

# opcje linkera
LDLIBS :=

# pliki do usunięcia dla make clean
CLEAN_C := $(shell find . -type f -name "*.o")
CLEAN_C += $(shell find . -type f -name "*.d")
CLEAN_C += $(shell find . -type f -name "*~")

# pliki do usunięcia dla make clean-all
CLEAN_ALL_C :=
CLEAN_ALL_C += $(shell find . -type f -name "a.out")

# pliki nie do usuwania
DONT_CLEAN_ALL_C := ! -name '*.*'
DONT_CLEAN_ALL_C += -a ! -name Makefile

# eof.