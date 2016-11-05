#include <stdio.h>

int solution(int A[], int N) {
    if (N <= 0) { return -1; }
    int answer = 0;
    int i, cnt = 1;
    for (i=1; i<N; i++) {
        if (A[i] == A[answer]) {
            cnt++;
        } else if (--cnt == 0) {
            answer = i;
            cnt = 1;
        }
    }
    for (i=0, cnt=0; i<N; i++) {
        if (A[i] == A[answer]) {
            cnt++;
        }
    }
    
    
    if ((cnt << 1) <= N) {
        return 0;
    }
    
    int pre_cnt = 0;
    int sum = 0;
    for (i=0; i<N; i++) {
        if (A[i] == A[answer]) {
            pre_cnt++;
        }
        if ((pre_cnt << 1) > i+1 && ((cnt - pre_cnt) << 1) > N-i-1) {
            sum++;
        }
    }
    return sum;
}

int main(int argc, char *argv[]) {
    //int A[] = {3, 4, 3, 2, 3, -1, 3, 3};
    //int A[] = {};
    //int A[] = {1};
    //int A[] = {1, 2};
    //int A[] = {1, 1, 1, 2, 2, 2};
    int A[] = {4, 3, 4, 4, 4, 2};
    printf("%d\n", solution(A, sizeof(A)/sizeof(int)));
	return 0;
}
