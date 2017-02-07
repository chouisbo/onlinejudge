#include <stdio.h>
#include <stdint.h>

// delete the lowest set bit 1 from n at each iteration

int hammingWeight(uint32_t n) {
    if (0 == n) return 0;
    uint32_t nOne = 0;
    while (n != 0) {
        n &= n-1;
        nOne++;
    }
    return nOne;
}


int main(int argc, const char *argv[]) {
    printf("%d\n", hammingWeight(256));
    printf("%d\n", hammingWeight(257));
    printf("%d\n", hammingWeight(258));
    printf("%d\n", hammingWeight(259));
    return 0;
}

