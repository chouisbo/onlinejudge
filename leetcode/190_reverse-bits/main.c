#include <stdio.h>
#include <stdint.h>

/*
 * For example, 
 * given input 43261596 (represented in binary as 00000010100101000001111010011100), 
 * return     964176192 (represented in binary as 00111001011110000010100101000000).
 *
 * Follow up:
 * If this function is called many times, how would you optimize it?
 *
 */

uint32_t reverseBits(uint32_t n) {

    uint32_t r = (n & 0x00000001);

    for (int i=1; i<32; i++) {
        r = r << 1;
        n = n >> 1;
        r += (n & 0x00000001);
    }

    return r;
}

void printUint32_tBits(uint32_t n) {
    char stack[32];
    int top = 0;
    for(int i=0; i<32; i++) {
        stack[top++] = '0' + (n & 0x00000001);
        n = n >> 1;
    }
    while (top >= 0) {
        printf("%c", stack[--top]);
    }
    printf("\n");
}

int main(void) {

    uint32_t x = 43261596;
    printf("%u => %u\n", x, reverseBits(x));
    printUint32_tBits(x);
    printUint32_tBits(reverseBits(x));

    return 0;
}

