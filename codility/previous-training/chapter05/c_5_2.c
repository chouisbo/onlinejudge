#include <stdio.h>
#include <stdlib.h>

int solution(char *S) {
    // write your code in C90
    int idx;
    int bracket_cnt = 0;
    char ch;
    for(idx=0; (ch = S[idx]) != '\0'; idx++) {
        switch(ch) {
        case '(':
            bracket_cnt++;
            break;
        case ')':
            if(bracket_cnt > 0) {
                bracket_cnt--;
                continue;
            }
            return 0;
        }
    }
    if(bracket_cnt <= 0) {
        return 1;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    char *S = "(()(())())";
    //char *S = "())";
    printf("%d\n", solution(S));
	return 0;
}
