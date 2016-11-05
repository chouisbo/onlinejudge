#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

struct Results {
    int * A;
    int M;
};

void printRs(const struct Results *pRs) {
    int i;
    for(i=0; i<pRs->M; i++) {
        printf("%d, ", pRs->A[i]);
    }
    printf("\n");
}

struct Results solution(char *S, int P[], int Q[], int M) {
    struct Results result;
    // write your code in C90
    
    result.A = (int *)malloc(sizeof(int) * M);
    result.M = M;
    
    const int N = strlen(S);
    int have[4][N], curHave[4];
    int i, j;
    for(i=0; i<4; i++) {
        for(j=0; j<N; j++) {
            have[i][j] = 0;
        }
        curHave[i] = 0;
    }
    for(i=0; i<N; i++) {
        switch(S[i]) {
        case 'A': curHave[0]++; break;
        case 'C': curHave[1]++; break;
        case 'G': curHave[2]++; break;
        case 'T': curHave[3]++; break;
        }
        for(j=0; j<4; j++) {
            have[j][i] = curHave[j];
        }
    }
    
    for(i=0; i<M; i++) {
        if(P[i] == Q[i]) {
            switch(S[P[i]]) {
            case 'A': result.A[i] = 1; break;
            case 'C': result.A[i] = 2; break;
            case 'G': result.A[i] = 3; break;
            case 'T': result.A[i] = 4; break;
            }
        } else {
            for(j=0; j<4; j++) {
                if(have[j][Q[i]] > have[j][P[i]]) {
                    result.A[i] = j+1;
                    break;
                } else if(have[j][Q[i]] == have[j][P[i]]) {
                    if(0 == P[i]) {
                        if(have[j][P[i]] != 0) {
                            result.A[i] = j+1;
                            break;
                        }
                    } else if(have[j][P[i]] > have[j][P[i]-1]) {
                        result.A[i] = j+1;
                        break;
                    }
                }
            }
        }
    }
    
    
    return result;
}


int main(void) {

    char *S = "AC";
    int P[] = {0, 0, 1};
    int Q[] = {0, 1, 1};
    
    struct Results rs = solution(S, P, Q, 3);
    printRs(&rs);

    return 0;
}

