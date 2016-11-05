#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEM_DIGIT_LEN 150

static char str[10];
static int n, dot;
static int res[MEM_DIGIT_LEN], a[MEM_DIGIT_LEN], b[MEM_DIGIT_LEN];
static int len, lena, lenb;

void mul() {
    int i, j;
    memset(res, 0, sizeof(res));
    for (i=1; i <= lena; i++) {
        for (j=1; j <= lenb; j++) {
            res[i+j-1] += a[i] * b[j];
            if (res[i+j-1] > 9) {
                res[i+j] += res[i+j-1] / 10;
                res[i+j-1] %= 10;
            }
        }
    }

    if (res[lena+lenb-1] > 9) {
        res[lena+lenb] += res[lena+lenb-1] / 10;
        res[lena+lenb-1] %= 10;
    }
    lena = lena + lenb;
    for (i=1; i <= lena; i++) a[i] = res[i];
}

int main() {
    int i, j, head, tail;
    while (scanf("%s %d", str, &n) != EOF) {
        dot = -1;
        for (i=5, j=1; i >= 0; i--) {
            if (str[i] != '.') {
                a[j] = str[i] - '0';
                b[j] = a[j];
                j++;
            } else {
                dot = i;
            }
        }
        lena = lenb = 5;
        for (i=1; i<n; i++) mul();

        /* printf("%s => dot @%d, len = %d, n = %d, lena = %d\n", str, dot, 5-dot, n, lena); */
        int pos_dot = n * (5-dot);

        head = lena, tail = 1;
        while (0 == a[head] && head != pos_dot) --head;
        while (0 == a[tail] && tail != pos_dot) ++tail;
        
        for (i = lena; i >= tail; i--) {
            if (i > head) continue;
            if (pos_dot == i) {
                if (pos_dot == tail) break;
                printf(".");
            }
            printf("%d", a[i]);
        }
        printf("\n");

    }
    return 0;
}

