#
# Makefile
# Copyright (c) 2023-2024 Jarosław Stańczyk <jaroslaw@stanczyk.pro>
#
TOOLS := ./make
include $(TOOLS)/make1b.mk
include $(TOOLS)/make_c1.mk
INDENT_SUBDIR = yes

# kompilowanie wszystkich kompilowalnych przykładów
.PHONY: all
all:
	@for dir in ??; do \
		if [ -d $${dir} -a $${dir} != "00" -a $${dir} != "make" ]; then \
			cd "$${dir}"; \
				$(MAKE) -j6 $@; \
			cd ..; \
		fi; \
	done

include $(TOOLS)/make_c2.mk
include $(TOOLS)/make_clean.mk
# eof.