// you can write to stdout for debugging purposes, e.g.
// // printf("this is a debug message\n");
//
int solution(int A, int B, int K) {
    // write your code in C99 (gcc 4.8.2)
    int rs = B/K - A/K;
    if (A % K == 0) {
        rs++;
    }
    return rs;
}
