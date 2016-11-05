// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int solution(int X, int A[], int N) {
    // write your code in C99 (gcc 4.8.2)
    int cnt = 0;
    short *cntFlag = (short *) malloc(sizeof(short) * X+1);
    for (int i=0; i<X+1; i++) {
        cntFlag[i] = 0;
    }
    for (int i=0; i<N; i++) {
        if (A[i] <= X) {
            if (!cntFlag[A[i]]) {
                if (++cnt >= X) return i;
                cntFlag[A[i]] = 1;
            }
        }
    }
    
    return -1;
}
