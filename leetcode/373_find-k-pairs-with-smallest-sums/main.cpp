
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;


struct Item {
    int a;
    int b;
    bool operator < (const Item &other) const {
        return (a+b) < (other.a + other.b);
    }
    Item(int x, int y):a(x), b(y) {}
};

class Solution {

public:

    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<Item> q;
        for (vector<int>::const_iterator it = nums1.begin();
             it != nums1.end(); ++it) {
            for (vector<int>::const_iterator jt = nums2.begin();
                 jt != nums2.end(); ++jt) {
                if ((int) q.size() == k) {
                    Item x = q.top();
                    if (x.a+x.b <= (*it+*jt)) {
                        continue;
                    } else {
                        q.pop();
                    }
                }
                q.push(Item(*it, *jt));
            }
        }
        vector<pair<int, int>> rs;
        while (! q.empty()) {
            Item x = q.top();
            rs.push_back(pair<int, int>(x.a, x.b));
            q.pop();
        }
        
        reverse(rs.begin(), rs.end());
        return rs; 
    }

};


int main(void) {

    vector<int> nums1 = {1, 7, 11};
    vector<int> nums2 = {2, 4, 6};
    const int K = 3;
    Solution s;
    for (auto &x : s.kSmallestPairs(nums1, nums2, K)) {
        cout << "(" << x.first << ", " << x.second << ")" << endl;
    }

    return 0;
}


