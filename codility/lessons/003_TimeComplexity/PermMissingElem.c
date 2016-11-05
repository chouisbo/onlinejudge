// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int solution(int A[], int N) {
    // write your code in C99 (gcc 4.8.2)
    long sum = 0;
    for (int i=0; i<N; i++) {
        sum += A[i];
    }
    return (int)((long)(N+1)*(N+2)/2 - sum);
}

int solution(int A[], int N) {
    int miss = 0;
    for (int i=0; i<N; i++) {
        miss ^= A[i];
    }
    for (int i=1; i<=N+1; i++) {
        miss ^= i;
    }
    return miss;
}

