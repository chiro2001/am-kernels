ARCH_SPLIT = $(subst -, ,$(ARCH))
ISA        = $(word 1,$(ARCH_SPLIT))
PLATFORM   = $(word 2,$(ARCH_SPLIT))

ALL_ASM = $(basename $(notdir $(shell find assembly/$(ISA)/. -name "*.S")))
ASM_ARG = $(word 2,$(subst -, ,$(MAKECMDGOALS)))
ifeq ($(ASM_ARG), reg)
ASM_ARG = run
endif

include pass.mk

ifdef PASS
ALL_ASM = $(PASS)
endif

asm-all: $(addprefix ASM.mk., $(ALL_ASM))
	@echo "All assembly tests:" $(ALL_ASM) $(ASM_ARG)

asm: asm-all

asm-gdb: asm

asm-run: asm-all
	@cat $(RESULT)
	@rm $(RESULT)

asm-reg: asm-run

$(ALL_ASM): %: ASM.mk.%

ASM.mk.%: assembly/$(ISA)/%.S latest
	@/bin/echo -e "NAME = $*\nSRCS = $<\nNO_LIB = true\ninclude $${AM_HOME}/Makefile" > $@
	@if make -s -f $@ ARCH=$(ARCH) $(ASM_ARG); then \
		printf "[%14s] $(COLOR_GREEN)PASS!$(COLOR_NONE)\n" $* >> $(RESULT); \
	else \
		printf "[%14s] $(COLOR_RED)FAIL!$(COLOR_NONE)\n" $* >> $(RESULT); \
	fi
	-@rm ASM.mk.*
	
