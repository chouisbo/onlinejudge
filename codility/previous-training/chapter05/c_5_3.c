#include <stdio.h>
#include <stdlib.h>

int solution(int H[], int N) {
    // write your code in C90
    int stack[N];
    int top = -1;
    int i, answer = 0;
    for(i=0; i<N; i++) {
        while(top > -1 && stack[top] > H[i]) {
            top--;
        }
        if(top == -1 || stack[top] < H[i]) {
            answer++;
            stack[++top] = H[i];
        }
    }
    return answer;
}

int main(int argc, char *argv[]) {
    int H[] = {8, 8, 5, 7, 9, 8, 7, 4, 8};
    printf("%d\n", solution(H, 9));
	return 0;
}
