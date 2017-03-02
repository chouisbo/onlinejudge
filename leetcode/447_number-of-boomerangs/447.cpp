#include <algorithm>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int count = 0;
        for (vector<pair<int, int>>::const_iterator it = points.begin();
             it != points.end(); it++) {
            map<int, int> distMap;
            for (vector<pair<int, int>>::const_iterator ij = points.begin();
                ij != points.end(); ij++) {
                if (it == ij) continue;
                int dist = (it->first - ij->first) * (it->first - ij->first)
                         + (it->second - ij->second) * (it->second - ij->second);
                
                if (distMap.find(dist) == distMap.end()) {
                    distMap[dist] = 0;
                }
                count += distMap[dist] * 2;
                distMap[dist]++;
            }
        }
        return count;
    }
};

