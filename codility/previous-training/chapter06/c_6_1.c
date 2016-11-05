#include <stdio.h>



void printArray(int *p, int n) {
    int i;
    for(i=0; i<n; i++) {
        printf("%d, ", p[i]);
    }
    printf("\n");
}

#include <assert.h>
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int _qsort(int *pA, int k, int n) {
    
    if (n == 1) {
        assert(k <= 1);
        return *pA;
    }
    
    int lo = 0;
    int hi = n-1;
    int mid = (hi - lo)/2 + lo;
    
    if (pA[mid] < pA[lo]) {
        swap(pA+mid, pA+lo);
    }
    if (pA[hi] < pA[mid]) {
        swap(pA+hi, pA+mid);
    } else {
        goto jump_over;
    }
    if(pA[mid] < pA[lo]) {
        swap(pA+mid, pA+lo);
    }
    
jump_over:
    
    do  {
        while (pA[lo] < pA[mid]) lo++;
        while (pA[mid] < pA[hi]) hi--;

        if (lo < hi) {
            swap(pA+lo, pA+hi);
            if (mid == lo) {
                mid = hi;
            } else if (mid == hi) {
                mid = lo;
            }
            lo++, hi--;
        } else if (lo == hi) {
            lo++, hi--;
            break;
        }
    } while (lo <= hi);
    
    
    //printf("lo => %d, mid => %d, hi => %d\n", lo, mid, hi);
    //printArray(pA, n);
    //printf("##########################################################\n");
    
    if (mid == k-1) {
        return pA[mid];
    } else if (mid > k-1) {
        return _qsort(pA, k, mid);
    } else {
        return _qsort(pA+mid+1, k-mid-1, n-mid-1);
    }
}


int solution(int A[], int N) {
    if(N == 0) return -1;
    if(N == 1) return 0;
    // write your code in C90
    int *B = (int *)malloc(sizeof(int) * N);
    int i, j = -1;
    for(i=0; i<N; i++) {
        B[i] = A[i];
    }
    int value = _qsort(&B[0], (N+1)/2, N);
    free(B);
    int cnt;
    for(i=N-1, cnt=0; i>=0; i--) {
        if(A[i] ==  value) {
            cnt++;
            j = i;
        }
    }
    //printf("value = %d, cnt = %d\n", value, cnt);
    if (cnt <= N/2) {
        return -1;
    } else {
        return j;
    }
}

int main(int argc, char *argv[]) {
    //int A[] = {1,0};
    int A[] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 
               3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
    printf("%d\n", solution(A, 21));
    
	return 0;
}
