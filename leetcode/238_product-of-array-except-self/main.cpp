/*
 * Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
 *
 * Solve it without division and in O(n).
 *
 * For example, given [1,2,3,4], return [24,12,8,6].
 *
 * Follow up:
 * Could you solve it with constant space complexity? 
 * (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const size_t LEN = nums.size();
        if (0 == LEN) return nums;
        vector<int> output {1};
        for (size_t i = 1; i < LEN; i++) {
            output.push_back(output[i-1] * nums[i-1]);
        }
        int product = 1;
        for (size_t i = 1; i <= LEN; i++) {
            output[LEN-i] = output[LEN-i] * product;
            product *= nums[LEN-i];
        }
        return output;
    }
};

void printProductExceptSelf(vector<int> data) {
    Solution s;
    for (auto &x : s.productExceptSelf(data)) {
        cout << x << ", ";
    }
    cout << endl;
}

int main(void) {
    printProductExceptSelf(vector<int> {1});
    printProductExceptSelf(vector<int> {1,2});
    printProductExceptSelf(vector<int> {1,2,3});
    printProductExceptSelf(vector<int> {1,2,3,4});
    return 0;
}


