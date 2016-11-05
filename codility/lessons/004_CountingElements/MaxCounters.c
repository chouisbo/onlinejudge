// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

struct Results solution(int N, int A[], int M) {
    struct Results result;
    // write your code in C99 (gcc 4.8.2)
    int *cs = (int *) malloc(sizeof(int) * (N+1));
    for (int i=0; i<N+1; i++) cs[i] = 0;
    int accum=0, sum=0;
    for (int i=0; i<M; i++) {
        if (A[i] <= 0 || A[i] > N+1) continue;
        if (A[i] <= N) {   // 1 <= A[i] <= N
            if (cs[A[i]] < accum) cs[A[i]] = accum;
            cs[A[i]]++;
            if (cs[A[i]] > sum) sum = cs[A[i]];
        } else {           // A[i] == N+1
            accum = sum;
        }
    }
    for (int i=0; i<N+1; i++) {
        if (cs[i] < accum) 
            cs[i] = accum;
    }
    
    result.C = &cs[1];
    result.L = N;
    
    return result;
}
