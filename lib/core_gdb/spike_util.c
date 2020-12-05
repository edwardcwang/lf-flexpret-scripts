#ifndef _SPIKE_UTIL
#define _SPIKE_UTIL

#include <stdint.h>

/**
 * Halt the spike simulation and return a value.
 * See https://github.com/riscv/riscv-tests/blob/master/benchmarks/common/syscalls.c#L56
 */
void __spike_return(uint32_t code) {
    // Spike tohost layout
    // bit 0: must be set to 1
    // All other bits are code << 1
    uint32_t tohostValue = (code << 1) | 1;
    // See https://www.pygears.org/blog/riscv/setup.html
    asm(
        "mv t0, %0\n"
        "la t1, tohost\n"
        "sw t0, 0(t1)\n"
        : // outputs
        : "r"(tohostValue) // inputs
        : // clobbers
        );
    while(1) {}
}

#endif
