#
# make_c2.mk
# Copyright (c) 2023 Jarosław Stańczyk <jaroslaw@stanczyk.pro>
#
CLEAN += clean-c
CLEAN_ALL += clean-all-c

.PHONY: clean-c
clean-c:
ifneq ($(strip $(CLEAN_C)),)
	$(begin)
	$(RM) $(CLEAN_C)
	$(end)
endif

CLEAN_ALL_C += $(shell find . -type f $(DONT_CLEAN_ALL_C))
.PHONY: clean-all-c
clean-all-c:
ifneq ($(strip $(CLEAN_ALL_C)),)
	$(begin)
	$(RM) $(CLEAN_ALL_C)
	$(end)
endif

# eof.