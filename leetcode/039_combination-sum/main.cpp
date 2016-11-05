/*
 * Given a set of candidate numbers (C) and a target number (T), 
 * find all unique combinations in C where the candidate numbers sums to T.
 *
 * The same repeated number may be chosen from C unlimited number of times.
 *
 * Note:
 * All numbers (including target) will be positive integers.
 * Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 * The solution set must not contain duplicate combinations.
 * For example, given candidate set 2,3,6,7 and target 7, 
 * A solution set is: 
 * [7] 
 * [2, 2, 3] 
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        rs.clear(); picked.clear();
        sort(candidates.begin(), candidates.end());
        comSum(0, candidates, target);
        return rs;
    }

private:
    vector<vector<int>> rs;
    vector<int> picked;

    void comSum(size_t si, const vector<int>& candidates, int target) {
        if (0 == target) rs.push_back(picked); // find one solution
        if (si >= candidates.size() || target < candidates[si]) return; // no solution

        // choose candidates[si] and don not move cursor
        picked.push_back(candidates[si]);
        comSum(si, candidates, target-candidates[si]);
        picked.pop_back();

        // drop si
        comSum(si+1, candidates, target);
    }
};

int main(void) {
    Solution s;
    vector<int> array {8, 7, 4, 3};
    for (auto &row : s.combinationSum(array, 11)) {
        for (auto &x : row) {
            cout << x << ", ";
        }
        cout << endl;
    }
    return 0;
}

