// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

struct Results solution(char *S, int P[], int Q[], int M) {
    struct Results result;
    // write your code in C99 (gcc 4.8.2)
    const int N = strlen(S);
    int *cs[4];
    for (int i=0; i<4; i++) {
        cs[i] = (int *) malloc(sizeof(int) * (N+1));
    }
    for (int i=0; i<4; i++) {
        for (int j=0; j<=N; j++) {
            cs[i][j] = 0;
        }
    }
    for (int i=0, j=1; i<N; i++, j++) {
        for (int k=0; k<4; k++) {
            cs[k][j] = cs[k][i];
        }
        if ('A' == S[i]) {
            cs[0][j]++;
        } else if ('C' == S[i]) {
            cs[1][j]++;
        } else if ('G' == S[i]) {
            cs[2][j]++;
        } else if ('T' == S[i]) {
            cs[3][j]++;
        }
    }
    
    result.A = (int *) malloc(sizeof(int) * M);
    result.M = M;
    for (int i=0; i<M; i++) {
        // printf("i = %d\n", i);
        for (int j=0; j<4; j++) {
            // printf("j = %d, %d - %d, ", j, cs[j][Q[i]+1] , cs[j][P[i]]);
            if (cs[j][Q[i]+1] - cs[j][P[i]] > 0) {
                result.A[i] = j+1;
                break;
            }
        }
        // printf("\n");
    }
    
    for (int i=0; i<4; i++) free(cs[i]);
    return result;
}
