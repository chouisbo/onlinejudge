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
    return (cnt << 1) > N ? answer : -1;
}

int main(int argc, char *argv[]) {
    //int A[] = {3, 4, 3, 2, 3, -1, 3, 3};
    //int A[] = {};
    //int A[] = {1};
    //int A[] = {1, 2};
    //int A[] = {1, 1, 1, 2, 2, 2};
    int A[] = {1, 1, 2, 1, 2, 2, 2};
    printf("%d\n", solution(A, sizeof(A)/sizeof(int)));
	return 0;
}
