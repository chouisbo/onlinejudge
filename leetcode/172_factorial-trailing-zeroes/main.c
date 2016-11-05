#include <stdio.h>

int trailingZeroes(int n) {
    int cnt = 0;
    int q   = 5;
    int delta;
    while ((delta = n/q) > 0) {
        cnt += delta;
        // 429496729 = 2147483648(int32_max) / 5
        if (q > 429496729) break;
        q   *= 5;
    }   
    return cnt; 
}

int main(int argc, const char *argv[]) {

    trailingZeroes(1808548329);
    return 0;
}

