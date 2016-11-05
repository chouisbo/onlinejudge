#include <stdio.h>

int solution(int A[], int N) {
    
    int i;
    int sum = N+1;
    for(i = 0; i < N; i++) {
        sum ^= A[i] ^ (i+1);
    }
    return sum;

}


int main(void) {

    int A[] = {2, 3, 1, 5};
    printf("%d\n", solution(A, 4));

    return 0;
}

