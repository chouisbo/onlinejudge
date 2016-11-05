#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

struct Results {
    int * C;
    int L;
};

void printRs(const struct Results *pRs) {
    int i;
    for(i=0; i<pRs->L; i++) {
        printf("%d, ", pRs->C[i]);
    }
    printf("\n");
}

struct Results solution(int N, int A[], int M) {
    struct Results result;
    // write your code in C90
    
    result.C = (int *) calloc(N, sizeof(int));
    result.L = N;
    int i;
    int baseMax = 0;
    int curMax  = baseMax;
    
    for(i=0; i<M; i++) {
        if(A[i] <= N) {
            if(result.C[A[i]-1] < baseMax) {
                result.C[A[i]-1] = baseMax;
            }
            result.C[A[i]-1] += 1;
            if(result.C[A[i]-1] > curMax) {
                curMax = result.C[A[i]-1];
            }
        } else if(A[i] == N+1) {
            baseMax = curMax;
        }
    }
    
    for(i=0; i<N; i++) {
        if(result.C[i] < baseMax) {
            result.C[i] = baseMax;
        }
    }
    
    return result;
}

int main(void) {

    int A[] = {3, 4, 4, 6, 1, 4, 4};
    struct Results rs = solution(5, A, 7); 
    printRs(&rs);

    return 0;
}

