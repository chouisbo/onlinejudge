#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int solution(int A[], int N) {
    
    int C[N+1];
    int i;
    for(i=0; i<N+1; i++) { 
        C[i] = 0;
    }
    
    for(i=0; i<N; i++) {
        if(A[i] > N) return 0;
        if(C[A[i]] == 0) {
            C[A[i]]++;
        } else {
            return 0;
        }
    }
    
    return 1;
}


int main(void) {

    int A[] = {4, 1, 3};
    printf("%d\n", solution(A, 3));

    return 0;
}

