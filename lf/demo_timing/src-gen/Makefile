
XLEN ?= 32


src_dir = ../../../

RISCV_PREFIX ?= riscv$(XLEN)-unknown-elf-
RISCV_GCC ?= $(RISCV_PREFIX)gcc

RISCV_GCC_OPTS ?= \
				-DPREALLOCATE=1 -mcmodel=medany -static \
				-std=gnu99 \
				-O0 \
				-ffast-math -fno-common -fno-builtin-printf

RISCV_LINK ?= $(RISCV_GCC) -T $(src_dir)lib/common/link.ld $(incs)
RISCV_LINK_OPTS ?= -g -static -nostartfiles -lm -lgcc -T $(src_dir)lib/common/link.ld

RISCV_OBJDUMP ?= $(RISCV_PREFIX)objdump --disassemble-all --disassemble-zeroes --section=.text --section=.text.startup --section=.text.init --section=.data

incs  += -I$(src_dir)lib/common

hello.riscv: $(wildcard ./*.c) $(wildcard $(src_dir)lib/common/*.c) $(wildcard $(src_dir)lib/common/*.S)
	$(RISCV_GCC) $(incs) $(RISCV_GCC_OPTS) $(RISCV_LINK_OPTS) -o $@ \
	$(wildcard ./*.c) \
	$(wildcard $(src_dir)lib/common/*.c) $(wildcard $(src_dir)lib/common/*.S)

hello.dump: hello.riscv
	$(RISCV_OBJDUMP) $< > $@

hello.dump.annot: hello.riscv
	$(RISCV_OBJDUMP) -S $< > $@

all: hello.riscv hello.dump hello.dump.annot

clean:
	-rm -rf *.riscv *.dump *.dump.annot



