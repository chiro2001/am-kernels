ARCH_SPLIT = $(subst -, ,$(ARCH))
ISA        = $(word 1,$(ARCH_SPLIT))
PLATFORM   = $(word 2,$(ARCH_SPLIT))

ASM = $(basename $(notdir $(shell find assembly/$(ISA)/. -name "*.S")))
ASM_ARG = $(word 2,$(subst -, ,$(MAKECMDGOALS)))
ifeq ($(ASM_ARG), reg)
ASM_ARG = run
endif

include pass.mk

ifdef PASS
ASM = $(PASS)
endif

asm-all: $(addprefix ASM.mk., $(ASM))
	@echo "All assembly tests:" $(ASM)

asm: asm-all

asm-gdb: asm

asm-run: asm-all

asm-reg: asm-run

$(ASM): %: ASM.mk.%

ASM.mk.%: assembly/$(ISA)/*/%.S latest
	@/bin/echo -e "NAME = $*\nSRCS = $<\nNO_LIB = true\ninclude $${AM_HOME}/Makefile" > $@
	@if make -s -f $@ ARCH=$(ARCH) $(ASM_ARG); then \
		printf "[%14s] $(COLOR_GREEN)PASS!$(COLOR_NONE)\n" $* >> $(RESULT); \
	else \
		printf "[%14s] $(COLOR_RED)FAIL!$(COLOR_NONE)\n" $* >> $(RESULT); \
		FAILED=true; \
	fi
	-@rm ASM.mk.*
	@cat $(RESULT)
	@rm $(RESULT)
	@if [ -n "$$FAILED" ]; then \
		exit 1; \
	fi
	
.PHONY: asm asm-all asm-run asm-gdb
