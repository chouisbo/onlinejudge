/*
 * Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
 *
 * For example,
 * If n = 4 and k = 2, a solution is:
 *
 * [
 * [2,4],
 * [3,4],
 * [2,3],
 * [1,2],
 * [1,3],
 * [1,4],
 * ]
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        rs.clear(); picked.clear();
        com(1, n, k);
        return rs;
    }
private:
    vector<vector<int>> rs;
    vector<int> picked;
    void com(int s, int n, int k) {
        if (k <= 0 || n < s || k > n-s+1) return;
        if (k == n-s+1) {
            for (int i = s; i <= n; i++) {
                picked.push_back(i);
            }
            rs.push_back(picked);
            while (k--) picked.pop_back(); 
        } else { // k < n-s+1
            // choose s
            picked.push_back(s);
            if (1 == k) rs.push_back(picked);
            else com(s+1, n, k-1);
            picked.pop_back();
            // drop s
            com(s+1, n, k);
        }
    }
};

int main(void) {
    Solution s;
    for (auto &row : s.combine(4, 2)) {
        for (auto &x : row) {
            cout << x << ", ";
        }
        cout << endl;
    }
    return 0;
}

