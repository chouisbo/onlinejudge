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


// to calculate the hammingWeight of (x ^ y) [xor]
// refer to Problem 191, there is one way to calculate hammingWeight at O(1) time complexity.
int hammingDistance(int x, int y) {

    int n = x ^ y;

    // calculate hammingWeight of n
    n -= (n >> 1) & 0x55555555;
    n = (n & 0x33333333) + (n >> 2 & 0x33333333);
    n = (n + (n >> 4)) & 0x0F0F0F0F;
    return n * 0x01010101 >> 24;

}


int main(void) {
    printf("%d\n", hammingDistance(1, 4));
    return 0;
}

