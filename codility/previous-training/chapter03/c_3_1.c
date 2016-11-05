#include <stdio.h>
#include <math.h>

int solution(int A[], int N) {
    // write your code in C90
    long prefix_zero_cnt = 0L;
    long passing_car_cnt = 0L;
    int i;
    for(i=0; i<N; i++) {
        switch(A[i]) {
        case 0:
            prefix_zero_cnt++;
            break;
        case 1:
            passing_car_cnt += prefix_zero_cnt;
            break;
        }
        if(passing_car_cnt > 1000000000L) {
            return -1;
        }
    }
    return passing_car_cnt;
}


int main(void) {

    int A[] = {0, 1, 0, 1, 1};
    printf("%d\n", solution(A, 5));

    return 0;
}

