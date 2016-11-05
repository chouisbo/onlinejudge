/*
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 *
 * The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 *
 * How many possible unique paths are there?
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m < 1 || n < 1) return 0;
        return cnr(m-1+n-1, n-1);
    }

private:
    int C[101][101];
    int cnr(int m, int n) {
        if (0 == n || m == n) return 1;
        if (m < n) return cnr(n, m);
        if (0 == C[m][n]) {
            C[m][n] = cnr(m-1, n) + cnr(m-1, n-1);
        }
        return C[m][n];
    }
};

int main(void) {
    Solution s;
    cout << s.uniquePaths(23, 12) << endl;
    return 0;
}

