/*
 * Given an array of integers, every element appears three times except for one. 
 * Find that single one.
 *
 * Note:
 * Your algorithm should have a linear runtime complexity. 
 * Could you implement it without using extra memory?
 *
 * [solution](http://fisherlei.blogspot.jp/2013/11/leetcode-single-number-ii-solution.html)
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> vBit(32, 0);
        for (auto &x : nums) {
            size_t idx = 0, len = 32;
            while (len--) {
                if (x & 0x1) vBit[idx]++; 
                x >>= 1;
                idx++;
            }
        }
        int rs = 0, shift = 0;
        for (auto &x : vBit) {
            if ((x % 3) != 0) {
                rs += (1 << shift); 
            }
            shift++;
        }
        return rs;
    }
};

int main(void) {
    Solution s;
    vector<int> nums1 {1, 2, 3, 4, 5, 3, 4, 5, 1, 5, 4, 3, 1};
    cout << s.singleNumber(nums1) << endl;
    vector<int> nums2 {-2, -2, 1, 1, -3, 1, -3, -3, -4, -2};
    cout << s.singleNumber(nums2) << endl;
    return 0;
}

