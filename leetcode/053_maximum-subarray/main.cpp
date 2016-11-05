#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() > 0) {
            int max = nums[0];
            int sum = nums[0];
            for (size_t i = 1; i < nums.size(); i++) {
                if (sum <= 0) {
                    if (nums[i] >= sum) sum = nums[i];
                } else {
                    sum += nums[i];
                }
                if (sum > max) max = sum;
            }
            return max;
        } else {
            return 0;
        }
    }
};

int main(void) {
    vector<int> array = {-2,1,-3,4,-1,2,1,-5,4};
    Solution s;
    cout << s.maxSubArray(array) << endl;
    return 0;
}
