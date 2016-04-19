YOUR_PROGRAM_VERSION := $(shell your_program --version 2>/dev/null)

all:
ifdef YOUR_PROGRAM_VERSION
	@echo "Found version $(YOUR_PROGRAM_VERSION)"
else
	@echo Not found
endif
