#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int moves = 0;
        vector<int>::const_iterator minIt = min_element(nums.begin(), nums.end());
        for (vector<int>::const_iterator it = nums.begin();
             it != nums.end(); ++it) {
            moves += *it - *minIt;
        }
        return moves;
    }
};

int main(void) {

    Solution s;
    vector<int> nums{1,2,3,4};
    cout << s.minMoves(nums) << endl;

    return 0;
}
