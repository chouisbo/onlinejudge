/*
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 *
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *
 * Find the minimum element.
 *
 * You may assume no duplicate exists in the array.
 */

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty()) assert(false);
        if (1 == nums.size()) return nums[0];
        if (2 == nums.size()) return nums[0] > nums[1] ? nums[1] : nums[0];
        int first = nums.front(), last = nums.back();
        size_t low = 0, high = nums.size()-1, mid;
        while (low+1 < high) {
            mid = (high-low)/2 + low;
            if (nums[mid] < first) {
                high = mid; last = nums[high];
            } else if (nums[mid] > last) {
                low = mid; first = nums[low];
            } else { // first <= nums[mid] <= last;
                return first;
            }
        }
        return nums[low] < nums[high] ? nums[low] : nums[high];
    }
};

int main(void) {
    /* vector<int> nums {4,5,6,7,0,1,2}; */
    vector<int> nums {1,2,3};
    Solution s;
    cout << s.findMin(nums) << endl;
    return 0;
}

