#include <deque>
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vRs;
        deque<int>  d;
        vector<int> v;
        for (int i=0; i<numRows; i++) {
            d.push_front(1);
            for (int j=1, k=2; k < d.size(); j++, k++) {
                d[j] += d[k];
            }
            v.assign(d.begin(), d.end());
            vRs.push_back(v);
        }
        return vRs;
    }
};
