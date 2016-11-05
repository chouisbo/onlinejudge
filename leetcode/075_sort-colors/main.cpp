/*
 * Given an array with n objects colored red, white or blue, 
 * sort them so that objects of the same color are adjacent, 
 * with the colors in the order red, white and blue.
 *
 * Here, we will use the integers 0, 1, and 2 to represent 
 * the color red, white, and blue respectively.
 *
 * Note:
 * You are not suppose to use the library's sort function for this problem.
 *
 * Follow up:
 * A rather straight forward solution is a two-pass algorithm using counting sort.
 * First, iterate the array counting number of 0's, 1's, and 2's, 
 * then overwrite array with total number of 0's, then 1's and followed by 2's.
 *
 * Could you come up with an one-pass algorithm using only constant space?
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        size_t p0 = 0, p1 = 0, p2 = 0; 
        for (size_t i = 0; i < nums.size(); i++) {
            switch (nums[i]) {
            case 0: nums[p0++] = 0;
                    if (p1 > 0) nums[p1++] = 1;
                    if (p2 > 0) nums[p2++] = 2;
                    break;
            case 1: if (0 == p1) p1 = p0;
                    nums[p1++] = 1;
                    if (p2 > 0) nums[p2++] = 2;
                    break;
            case 2: if (0 == p2) p2 = p1 > p0 ? p1 : p0;
                    nums[p2++] = 2;
                    break;
            }
        }
    }
};

int main(void) {
    Solution s;
    vector<int> colors1 {0,1,2,1,2,0,0,2,1,2,0,1,1,2};
    s.sortColors(colors1);
    for (auto &x : colors1) { cout << x << ", "; } cout << endl;
    vector<int> colors2 {1,0};
    s.sortColors(colors2);
    for (auto &x : colors2) { cout << x << ", "; } cout << endl;
    vector<int> colors3 {0,2};
    s.sortColors(colors3);
    for (auto &x : colors3) { cout << x << ", "; } cout << endl;
    return 0;
}

