#include <stdio.h>
#include <stdint.h>

int hammingDistance(int x, int y) {
    return __builtin_popcount(x ^ y);
}


int main(void) {
    printf("%d\n", hammingDistance(1, 4));
    return 0;
}

