#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_DEPTH 200000

int solution(char *S) {
    // write your code in C90
    
    char stack[MAX_DEPTH];
    int top = -1;
    int idx;
    char ch;
    for(idx=0; (ch = S[idx]) != '\0'; idx++) {
        switch(ch) {
        case '(':
        case '{':
        case '[':
            stack[++top] = ch;
            //printf("push %c\n", ch);
            break;
        case ')':
            if(stack[top] == '(') {
                //printf("pop (\n");
                top--;
                continue;
            }
            return 0;
        case ']':
            if(stack[top] == '[') {
                //printf("pop [\n");
                top--;
                continue;
            }
            return 0;
        case '}':
            if(stack[top] == '{') {
                //printf("pop {\n");
                top--;
                continue;
            }
            return 0;
        }
    }
    if(top == -1) {
        return 1;
    }
    return 0;
    
}



int main(void) {

    char *S = "{[()()]}";
    //char *S = "([)()]";
    printf("%d\n", solution(S));

    return 0;
}

