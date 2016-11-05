// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int solution(int A[], int N) {
    // write your code in C99 (gcc 4.8.2)
    int odd = A[0];
    for (int i = 1; i < N; i++) {
        odd = odd ^ A[i];
    }
    return odd;
}
