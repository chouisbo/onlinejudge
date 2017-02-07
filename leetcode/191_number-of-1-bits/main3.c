#include <stdio.h>
#include <stdint.h>

// solution at O(1)

int hammingWeight(uint32_t n) {
    n -= (n >> 1) & 0x55555555;
    n = (n & 0x33333333) + (n >> 2 & 0x33333333);
    n = (n + (n >> 4)) & 0x0F0F0F0F;
    return n * 0x01010101 >> 24;
}


int main(int argc, const char *argv[]) {
    printf("%d\n", hammingWeight(256));
    printf("%d\n", hammingWeight(257));
    printf("%d\n", hammingWeight(258));
    printf("%d\n", hammingWeight(259));
    return 0;
}

