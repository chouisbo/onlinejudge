#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define max(a, b) (((a)>=(b))?(a):(b))

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int solution(int A[], int N) {
    
    qsort(&A[0], N, sizeof(int), compare);
    int part1 = max(A[0]*A[1]*A[2], A[N-1]*A[N-2]*A[N-3]);
    int part2 = max(A[0]*A[N-1]*A[N-2], A[0]*A[1]*A[N-1]);
    
    return max(part1, part2);
}


int main(void) {

    int A[] = {-3, 1, 2, -2, 5, 6};
    printf("%d\n", solution(A, 6));

    return 0;
}

