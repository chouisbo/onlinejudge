/*
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to num2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
Subscribe to see which companies asked this question
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> rs;
        if (nums1.empty() || nums2.empty()) return rs;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        for (size_t i=0, j=0; i<nums1.size() && j<nums2.size();) {
            if (nums1[i] == nums2[j]) {
                rs.push_back(nums1[i]);
                i++; j++;
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }

        return rs;
    }
};

int main(void) {

    Solution s;
    vector<int> nums1 = {1, 2, 2, 1}; 
    vector<int> nums2 = {2, 2};

    for (auto &x : s.intersect(nums1, nums2)) {
        cout << x << ", ";
    }
    cout << endl;

    return 0;
}

