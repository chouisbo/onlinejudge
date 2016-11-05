#include <stdio.h>
#include <math.h>

int solution(int X, int Y, int D) {
    // write your code in C90
    
    return (Y - X + D-1) / D;
    
}



int main(void) {
   
    printf("%d\n", solution(10, 85, 30));

    return 0;
}

