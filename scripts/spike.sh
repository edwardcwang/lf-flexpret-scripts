#!/bin/bash
set -ex
set -euo pipefail

# Grab the PC start address from the ELF file
pc_start=$(riscv32-unknown-elf-objdump -x $1 | grep "0 _start" | cut -d " " -f1)
echo "PC starts at: ${pc_start}"

# Use -d for single-step debugging
# FlexPRET does not use the C extension.
spike --isa=RV32IM -m0x20000000:0x2000,0x40000000:0x1000,0x80000000:0x20000 $1

# Debug with GDB
# spike --rbb-port=9824 --isa=RV32IM -m0x20000000:0x2000,0x40000000:0x1000,0x80000000:0x20000 $1
