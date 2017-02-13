#include <vector>
#include <algorithm>
#include <iostream>
#include <bitset>

using namespace std;


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0), target = sum >> 1;
        if (sum & 1) return false;
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for (auto num : nums)
            for (int i = target; i >= num; i--)
                dp[i] = dp[i] || dp[i - num];
        return dp[target];
    }

    bool canPartition2(vector<int>& nums) {
        bitset<5001> bits(1);
        int sum = 0;
        for (auto n : nums) {
            sum += n;
            bits |= bits << n;
        }
        return !(sum & 1) && bits[sum >> 1];
    }
};


int main(void) {

    vector<int> nums1{1, 5, 11, 5};
    vector<int> nums2{1, 2, 3, 5};
    Solution s;
    cout << "nums1 [1, 5, 11, 5] canPartition is " << s.canPartition(nums1) << endl;
    cout << "nums2 [1, 2, 3, 5] canPartition is " << s.canPartition(nums2) << endl;
    cout << "nums1 [1, 5, 11, 5] canPartition is " << s.canPartition2(nums1) << endl;
    cout << "nums2 [1, 2, 3, 5] canPartition is " << s.canPartition2(nums2) << endl;

    return 0;
}

