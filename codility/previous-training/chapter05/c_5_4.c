#include <stdio.h>
#include <stdlib.h>

int solution(int A[], int B[], int N) {
    // write your code in C90
    int stack[N];
    int top = -1;
    int i;
    int answer = 0;
    for(i=0; i<N; i++) {
        switch(B[i]) {
        case 0:
            while(top > -1) {
                if(stack[top] > A[i]) {
                    break;
                }
                --top;
            }
            if(-1 == top) {
                answer++;
            }
            break;
        case 1:
            stack[++top] = A[i];
            break;
        }
    }
    return answer + top + 1;
}

int main(int argc, char *argv[]) {
    int A[] = {4, 3, 2, 1, 5};
    int B[] = {0, 1, 0, 0, 0};
    printf("%d\n", solution(A, B, 5));
	return 0;
}
