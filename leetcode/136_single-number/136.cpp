#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <fstream>

using namespace std;


// 
// Given an array of integers, every element appears twice except for one. Find that single one.
// Note:
// Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
//

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.size() <= 0) { return -1; }
        if (nums.size() == 1) { return nums[0]; }
        int _n = nums[0];
        for (vector<int>::size_type i=1; i<nums.size(); ++i) {
            _n = _n ^ nums[i];
        }
        return _n;
    }
};

int main(int argc, const char* argv[]) {

    vector<int> v = {1,1,2,3,3};

    Solution s;
    cout << s.singleNumber(v) << endl;
    

    return 0;
}
