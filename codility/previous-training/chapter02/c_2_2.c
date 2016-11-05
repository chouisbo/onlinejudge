#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int solution(int X, int A[], int N) {
    
    int C[X+1];
    int i;
    int sum = 0;
    for(i=0; i<X+1; i++) { C[i] = 0; }
    for(i=0; i<N; i++) {
        if(A[i] > X) continue;
        if(C[A[i]] == 0) {
            C[A[i]]++;
            sum++;
        }
        if(sum == X) break;
    }
    
    if(sum < X) return -1;
    return i;
    
}


int main(void) {

    int A[] = {1, 3, 1, 4, 2, 3, 5, 4};
    printf("%d\n", solution(5, A, 8));

    return 0;
}

