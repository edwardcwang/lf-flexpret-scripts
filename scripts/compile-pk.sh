#!/bin/bash
# Compile $1.c
set -ex
set -euo pipefail
echo "Compiling $1.c"

# FIXME: not sure why we need to set .text location to 0x8000_0100 instead of 0x8000_0000
# Spike tries to write to 0x7fff_f000 if we set it to 0x8000_0000
riscv32-unknown-elf-gcc -g -static -O0 -march=rv32i -mabi=ilp32 -o $1 $1.c
