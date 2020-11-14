#include "spike_util.c"

int main() {
    uint8_t* ptr = (uint8_t*)0x40000000;
    *ptr = 0x42;
    __spike_return(12345);
    return 0;
}
