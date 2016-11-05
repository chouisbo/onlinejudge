#include <stdio.h>

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    if (C <= E) return (C-A)*(D-B)+(G-E)*(H-F);
    if (G <= A) return (C-A)*(D-B)+(G-E)*(H-F);
    if (D <= F) return (C-A)*(D-B)+(G-E)*(H-F);
    if (H <= B) return (C-A)*(D-B)+(G-E)*(H-F);

    int lenX = 0;
    if (A <= E) {
        if (C <= G) lenX = C - E;
        else        lenX = G - E;
    } else {
        if (C <= G) lenX = C - A;
        else        lenX = G - A;
    }

    int lenY = 0;
    if (B <= F) {
        if (D <= H) lenY = D - F;
        else        lenY = H - F;
    } else {
        if (D <= H) lenY = D - B;
        else        lenY = H - B;
    }

    return (C-A)*(D-B)+((G-E)*(H-F)-(lenX*lenY));
}

int main(int argc, const char *argv[]) {
    printf("%d\n",  computeArea(-3, 0, 3, 4, 0, -1, 9, 2));
    printf("%d\n",  computeArea(1, -3, 3, -1, -2, -2, 2, 2));
    printf("%d\n",  computeArea(0, 0, 50000, 40000, 0, 0, 50000, 40000));
    return 0;
}


