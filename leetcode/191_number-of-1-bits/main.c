
#include <stdio.h>
#include <stdint.h>


int hammingWeight(uint32_t n) {
    if (0 == n) return 0;
    uint32_t nOne = 0;
    do {
        switch (n & 0xf) {
            case 0:  break;
            case 1:
            case 2:
            case 4:
            case 8:  nOne += 1; break;
            case 3:
            case 5:
            case 6:
            case 9:
            case 10:
            case 12: nOne += 2; break;
            case 7:
            case 11:
            case 13:
            case 14: nOne += 3; break;
            case 15: nOne += 4; break;
        }
    } while (n = n>>4);
    return nOne;
}


int main(int argc, const char *argv[]) {
    printf("%d\n", hammingWeight(256));
    printf("%d\n", hammingWeight(257));
    printf("%d\n", hammingWeight(258));
    printf("%d\n", hammingWeight(259));
    return 0;
}

