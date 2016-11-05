#include <iostream>
#include <vector>

using namespace std;

// you can also use includes, for example:
// #include <algorithm>
int solution(const vector<int> &A) {
    // write your code in C++98
    int n = A.size(), valley = 0, profit = 0;
    for (int i = 1; i < n; i++) {
        if (A[i] < A[valley]) {
            valley = i;
        }
        profit = max(profit, A[i]-A[valley]);
    }
    return profit;
}


int main(int argc, char** argv) {
    int A[] = {23171, 21011, 21123, 21366, 21013, 21367};
    vector<int> vA(A, A+sizeof(A)/sizeof(int));
    cout << solution(vA) << endl;
    
	return 0;
}
