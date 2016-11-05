int solution(int A[], int N) {
    // write your code in C99 (gcc 4.8.2)
    if (N <= 0) return 0;
    short *cs = (short *) malloc(sizeof(short) * (N+1));
    for (int i=0; i<N+1; i++) cs[i] = 0;
    for (int i=0; i<N; i++) {
        if (A[i] <=0 || A[i] > N) return 0;
        if (cs[A[i]]) return 0;
        else cs[A[i]] = 1;
    }    
    free(cs);
    return 1;
}
