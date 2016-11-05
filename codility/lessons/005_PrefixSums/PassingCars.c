// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int solution(int A[], int N) {
    // write your code in C99 (gcc 4.8.2)
    int sum = 0, accum = 0, rs = 0;
    for (int i=0; i<N; i++) sum += A[i];
    for (int i=0; i<N; i++) {
        if (0 == A[i]) {
            rs += sum - accum;
            if (rs > 1000000000) return -1;
        } else {
            accum++;
        }
    }
    return rs;
}
