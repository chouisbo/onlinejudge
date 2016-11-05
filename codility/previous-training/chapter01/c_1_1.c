#include <stdio.h>
#include <limits.h>

#define abs_long(x) ((x)>0L?(x):((x)*-1L)) 

int solution(int A[], int N) {
    
    int i;
    long sum = 0L;
    for(i=0; i<N; i++) { sum += A[i]; }
    long prefix_sum = 0L;
    long min_diff = LONG_MAX;
    for(i=0; i<N-1; i++) {
        prefix_sum += A[i];
        long abs_diff = abs_long(prefix_sum - (sum - prefix_sum));
        if(abs_diff < min_diff) {
            min_diff = abs_diff;
        }
    }
    return min_diff;

}


int main(void) {

    int A[] = {2, -2};
    printf("%d\n", solution(A, 2));

    return 0;
}

