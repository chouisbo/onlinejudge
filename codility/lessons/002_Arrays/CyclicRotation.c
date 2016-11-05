// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

struct Results solution(int A[], int N, int K) {
    struct Results result;
    // write your code in C99 (gcc 4.8.2)
    result.A = A;
    result.N = N;
    if (N <= 0) { return result; }
    int k = K % N;
    if (0 == k) { return result; }
    result.A = (int *)malloc(N * sizeof(int));
    for (int i = 0; i<N; i++) {
        result.A[(i+k)%N] = A[i];
    }
    result.N = N;
    return result;
}
