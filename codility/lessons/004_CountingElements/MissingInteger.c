// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int solution(int A[], int N) {
    // write your code in C99 (gcc 4.8.2)
    short *cs = (short *) malloc (sizeof(short)*(N+1));
    for (int i=0; i<N+1; i++) cs[i] = 0;
    for (int i=0; i<N; i++) {
        if (A[i] <= 0 || A[i] > N) continue;
        cs[A[i]] = 1;
    }
    int i;
    for (i=1; i<N+1; i++) {
        if (cs[i] != 1) break;
    }
    free(cs);
    return i;
}
