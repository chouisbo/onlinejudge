// you can also use includes, for example:
// #include <algorithm>
#include <vector>

int solution(vector<int> &A) {
    // write your code in C++98
    // 2 * size - 1 >= D
    // size < D
    int n = A.size();
    if (n <= 2) {
        return 0;
    }
    vector<int> sum;
    sum.resize(n);
    int last = -1, D = 0;
    sum[0] = 0;
    for (int i = 1; i + 1 < n; ++i) {
        sum[i] = sum[i - 1];
        if ((A[i] > A[i - 1]) && (A[i] > A[i + 1])) {
            D = max(D, i - last);
            last = i;
            ++sum[i];
        }
        
    }
    if ((sum[n - 1] = sum[n - 2]) == 0) {
        return 0;
    }
    D = max(D, n - last);
    for (int i = (D >> 1) + 1; i < D; ++i) {
        if (n % i == 0) {
            last = 0;
            int j;
            for (j = i; j <= n; j += i) {
                if (sum[j - 1] <= last) {
                    break;
                }
                last = sum[j - 1];
            }
            if (j > n) {
                return n / i;
            }
        }
    }
    for (last = D; n % last; ++last)
    ;
    return n / last;
            
}