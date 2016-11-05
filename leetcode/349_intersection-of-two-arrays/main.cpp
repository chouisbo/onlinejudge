/*
 *
 * Given two arrays, write a function to compute their intersection.
 *
 * Example:
 * Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
 *
 * Note:
 * Each element in the result must be unique.
 * The result can be in any order.
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> vIntersect;
        if (! nums1.empty() && ! nums2.empty()) {
            sort(nums1.begin(), nums1.end());
            sort(nums2.begin(), nums2.end());
            nums1.erase(unique(nums1.begin(), nums1.end()), nums1.end()); 
            nums2.erase(unique(nums2.begin(), nums2.end()), nums2.end()); 

            if (nums1.size() < nums2.size() && nums2.size() < 2*nums1.size()) {
                for (auto &x : nums1) {
                    if (binary_search(nums2.begin(), nums2.end(), x)) {
                        vIntersect.push_back(x);
                    }
                }
            } else if (nums2.size() < nums1.size() && nums1.size() < 2*nums2.size()) {
                for (auto &x : nums2) {
                    if (binary_search(nums1.begin(), nums1.end(), x)) {
                        vIntersect.push_back(x);
                    }
                }
            } else {
                vector<int>::const_iterator it1 = nums1.begin(), it2 = nums2.begin();
                while (it1 != nums1.end() && it2 != nums2.end()) {
                    if (*it1 == *it2) { vIntersect.push_back(*it1); it1++, it2++; }
                    else if (*it1 < *it2) it1++;
                    else it2++;
                }
            }
        }
        return vIntersect;
    }
};

int main(void) {

    Solution s;
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    for (auto &x : s.intersection(nums1, nums2)) {
        cout << x << ", ";
    }
    cout << endl;
    return 0;
}

