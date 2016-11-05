/*
 * Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
 *
 * You may assume no duplicates in the array.
 *
 * Here are few examples.
 * [1,3,5,6], 5 → 2
 * [1,3,5,6], 2 → 1
 * [1,3,5,6], 7 → 4
 * [1,3,5,6], 0 → 0
 *
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        size_t low = 0, high = nums.size(), mid;
        while (low < high) {
            mid = (high-low)/2+low;
            if (nums[mid] < target) {
                low = mid + 1;
            } else if (nums[mid] > target) {
                high = mid;
            } else { // nums[mid] == target
                return (int) mid;
            }
        }
        return (int) low;
    }
};

int main(void) {
    Solution s;

    vector<int> nums1 {1,3,5,6};
    cout << s.searchInsert(nums1, 5) << endl;
    vector<int> nums2 {1,3,5,6};
    cout << s.searchInsert(nums2, 2) << endl;
    vector<int> nums3 {1,3,5,6};
    cout << s.searchInsert(nums3, 7) << endl;
    vector<int> nums4 {1,3,5,6};
    cout << s.searchInsert(nums4, 0) << endl;

    return 0;
}

