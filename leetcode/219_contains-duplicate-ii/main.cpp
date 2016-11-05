#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.size() <= 1 || k <= 0) return false;
        unordered_map<int, int> hmap;
        unordered_map<int, int>::iterator itm = hmap.end();
        for (size_t i = 0; i < nums.size(); i++) {
            itm = hmap.find(nums[i]);
            if (itm == hmap.end()) {
                hmap.insert(pair<int, int>(nums[i], i));
            } else {
                if (itm->second + k < i) {
                    itm->second = i;
                } else {
                    return true;
                }
            }
        }
        return false;
    }
};

