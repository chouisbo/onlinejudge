#include <stdlib.h>

int compare (const void * a, const void * b)
{
    return ( *(char*)a - *(char*)b );
}

bool isAnagram(char* s, char* t) {
    char *ps = s, *pt = t;
    int lenS = 0, lenT = 0;
    while (*ps++ != '\0') lenS++; 
    while (*pt++ != '\0') lenT++;
    if (lenS != lenT) return false;
    ps = s; pt =t;
    qsort(ps, lenS, sizeof(char), compare);
    qsort(pt, lenT, sizeof(char), compare);
    while (*ps++ == *pt++ && lenS > 0) lenS--;
    return lenS == 0;
}

