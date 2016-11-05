
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {

public:

    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    	if (t < 0) return false;
    	if (k <= 0) return false;
    	if (nums.size() < 2) return false;

    	int i;
    	set<int> valSet;
    	set<int>::iterator it, it_lower;

    	for (i=0; i<nums.size() && i<k; ++i) {
    		it_lower = valSet.lower_bound((long)nums[i]-t);
			if (it_lower != valSet.end() && *it_lower <= (long)nums[i]+t) { 
				return true;
    		} else {
    			valSet.insert(nums[i]);
    		}
    	}

    	while (i<nums.size()) {
    		it_lower = valSet.lower_bound((long)nums[i]-t);
			if (it_lower != valSet.end() && *it_lower <= (long)nums[i]+t) { 
				return true;
    		} else {
    			valSet.erase(nums[i-k]);
    			valSet.insert(nums[i]);
    		}
    		i++;
    	}

        return false;
    }
    
};

