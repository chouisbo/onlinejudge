/*
 * Given a collection of distinct numbers, return all possible permutations.
 *
 * For example,
 * [1,2,3] have the following permutations:
 * [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
 *
 */

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> rs;
        sort(nums.begin(), nums.end());
        permuteRecursively(nums, 0, rs);
        return rs;
    }

    void permuteRecursively(vector<int>& nums, size_t si, vector<vector<int>>& rs) {
        if (si >= nums.size()) {
            rs.push_back(nums);
        } else {
            for (size_t i = si; i < nums.size(); i++) {
                swap(nums[i], nums[si]);
                permuteRecursively(nums, si+1, rs);
                swap(nums[i], nums[si]);
            }
        }
    }
};

int main(void) {
    vector<int> nums {1, 2, 3};
    Solution s;
    for (auto &row : s.permute(nums)) {
        for (auto &x : row) {
            cout << x << ", ";
        }
        cout << endl;
    }
    return 0;
}

