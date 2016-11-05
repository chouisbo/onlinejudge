#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> vRs;
        if (nums.size() <= 0) return vRs;
        int start = nums[0];
        int val   = start+1;
        for (int i=1; i<nums.size(); i++) {
            if (nums[i] != val) {
                if (start == (val-1)) {
                    vRs.push_back(to_string(start));
                } else {
                    string s = "";
                    s.append(to_string(start)).append("->").append(to_string(val-1));
                    vRs.push_back(s);
                }
                start = nums[i];
                val   = start+1;
            } else {
                val++;
            }
        }
        if (start == (val-1)) {
            vRs.push_back(to_string(start));
        } else {
            string s = "";
            s.append(to_string(start)).append("->").append(to_string(val-1));
            vRs.push_back(s);
        }
        return vRs;
    }
};


int main(int argc, const char *argv[]) {
    vector<int> nums {0, 1, 2, 4, 5, 7};
    Solution s;
    vector<string> vRs = s.summaryRanges(nums);
    for (vector<string>::const_iterator it = vRs.begin();
         it != vRs.end(); ++it) {
        cout << *it << endl;
    }
    return 0;
}

