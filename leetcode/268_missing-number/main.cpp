/*
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
 *
 * For example,
 * Given nums = [0, 1, 3] return 2.
 *
 * Note:
 * Your algorithm should run in linear runtime complexity. 
 * Could you implement it using only constant extra space complexity?
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        const int N = (int) nums.size();
        int miss = 0;
        for (int i=1; i <= N; i++) {
            miss ^= i;
            miss ^= nums[(size_t) (i-1)];
        }
        return miss;
    }
};

int main(void) {

    Solution s;
    vector<int> array1 {0, 1, 3};
    cout << s.missingNumber(array1) << endl;
    vector<int> array2 {3, 2, 0, 4, 6, 8, 1, 7, 9, 10};
    cout << s.missingNumber(array2) << endl;

    return 0;
}

