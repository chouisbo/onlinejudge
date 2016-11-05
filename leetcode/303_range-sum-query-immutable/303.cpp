
#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
    vector<int> vPrefixSum;

    NumArray(vector<int> &nums) {
        int sum = 0;
        for (auto &i : nums) {
            sum += i;
            vPrefixSum.push_back(sum);
        }
    }

    int sumRange(int i, int j) {
        if (j >= vPrefixSum.size()) {
            j = vPrefixSum.size()-1;
        }
        if (j < 0)  return 0;
        if (i <= 0) return vPrefixSum.at(j);
        else {
            return vPrefixSum.at(j)-vPrefixSum.at(i-1);    
        }
    }
};


int main(int argc, const char *argv[]) {

    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray numArray(nums);

    cout << numArray.sumRange(0, 2) << endl;
    cout << numArray.sumRange(2, 5) << endl;
    cout << numArray.sumRange(0, 5) << endl;

    return 0;
}
