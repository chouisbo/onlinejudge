#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
        if (nums.size() > 0) {
        	unordered_set<int> hset;
        	for (vector<int>::const_iterator it = nums.begin();
        		 it != nums.end(); ++it) {
        		if (hset.find(*it) != hset.end()) {
        			return true;
        		} else {
        			hset.insert(*it);
        		}
        	}
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
	vector<int> nums;
	// nums.push_back(1);
	// nums.push_back(2);
	// nums.push_back(3);
	// nums.push_back(4);
	// nums.push_back(3);
	Solution s;
	cout << s.containsDuplicate(nums) << endl;
	return 0;
}