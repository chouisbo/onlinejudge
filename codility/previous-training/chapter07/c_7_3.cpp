// you can also use includes, for example:
// #include <algorithm>
int solution(const vector<int> &A) {
    // write your code in C++98
    int n = A.size(), end = A[0], result = end;
    for (int i = 1; i < n; ++i) {
        if (end < 0) {
            end = 0;
        }
        result = max(result, end += A[i]);
    }
    return result;
}