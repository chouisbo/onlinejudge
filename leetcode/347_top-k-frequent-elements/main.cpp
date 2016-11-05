/*
 * Given a non-empty array of integers, return the k most frequent elements.
 *
 * For example,
 * Given [1,1,1,2,2,3] and k = 2, return [1,2].
 *
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Your algorithm's time complexity must be better than O(n log n), 
 * where n is the array's size.
 *
 */

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> countMap;
        map<int, int>::iterator it;
        for (auto &x : nums) {
            it = countMap.find(x);
            if (it != countMap.end()) it->second++;
            else countMap[x] = 1;
        }
        // Using lambda to compare elements.
        auto cmp = [](pair<int, int> left, pair<int, int> right) {
            return left.second > right.second;
        };
        priority_queue< pair<int, int>, vector< pair<int, int> >, decltype(cmp)> pq(cmp);
        it = countMap.begin();
        while (k-- && it != countMap.end()) pq.push(*it++);
        while (it != countMap.end()) {
            if (pq.top().second < it->second) {
                pq.pop();
                pq.push(*it);
            }
            it++;
        }
        vector<int> rs;
        while (!pq.empty()) {
            rs.push_back(pq.top().first);
            pq.pop();
        }
        reverse(rs.begin(), rs.end());
        return rs;
    }
};

int main(void) {
    Solution s;
    vector<int> data {3,1,2,1,2,1};
    for (auto &x : s.topKFrequent(data, 2)) {
        cout << x << ", ";
    }
    cout << endl;
}

