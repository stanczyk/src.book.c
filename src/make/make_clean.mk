#
# make_clean.mk
# Copyright (c) 2023 Jarosław Stańczyk <jaroslaw@stanczyk.pro>

# Clean targets
#
.PHONY: clean
clean: $(CLEAN)

.PHONY: clean-all
clean-all: clean $(CLEAN_ALL)

# eof.
