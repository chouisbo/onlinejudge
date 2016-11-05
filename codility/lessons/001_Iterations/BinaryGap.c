// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int solution(int N) {
    // write your code in C99 (gcc 4.8.2)
    int gap = 0;
    int maxGap = 0;
    while (! (N & 0x01)) {
        N >>= 1;
    }
    while (N > 0) {
        if (N & 0x01) {
            if (maxGap < gap) maxGap = gap;
            gap = 0;
        } else {
            gap++;
        }
        N >>= 1;
    }
    return maxGap;
}