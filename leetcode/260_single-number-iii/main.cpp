
/* http://fisherlei.blogspot.jp/2015/10/leetcode-single-number-iii-solution.html
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorAB = 0;
        for (auto &x : nums) {
            xorAB ^= x; 
        }
        int splitter = 1;
        while (0 == (xorAB & splitter)) {
            splitter <<= 1;
        }
        vector<int> partA, partB;
        int a = 0, b = 0;
        for (auto &x : nums) {
            if (x & splitter) {
                a ^= x;
            } else {
                b ^= x;
            }
        }
        return vector<int> {a, b};
    }
};

int main(void) {
    vector<int> nums {1, 2, 1, 3, 2, 5};
    Solution s;
    for (auto &x : s.singleNumber(nums)) {
        cout << x << ", ";
    }
    cout << endl;
    return 0;
}

