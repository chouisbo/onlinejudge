// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int solution(int A[], int N) {
    // write your code in C99 (gcc 4.8.2)
    long sum   = 0;
    long accum = 0;
    int minDiff = 0x0fffffff, diff;
    for (int i=0; i<N; i++) sum += A[i];
    for (int i=0; i<N-1; i++) {
        accum += A[i];
        diff = sum - (accum<<1);
        if (diff < 0) { diff = (~diff) + 1; }
        if (diff < minDiff) {
            minDiff = diff;
        }
    }
    return minDiff;
}
