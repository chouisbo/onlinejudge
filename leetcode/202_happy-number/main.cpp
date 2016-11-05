#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, bool>::const_iterator itMap = happyMap.find(n);
        if (itMap == happyMap.end()) {
            unordered_set<int>::const_iterator itSet = circleSet.find(n);
            if (itSet == circleSet.end()) {
                circleSet.insert(n);
                return isHappy(sqareDigitSum(n));
            } else {
                if (1 == *itSet) {
                    fillSetToMap(true);
                    return true;
                } else {
                    fillSetToMap(false);
                    return false;
                }
            }
        } else {
            fillSetToMap(itMap->second);
            return itMap->second;
        }
    }

private:
    unordered_set<int> circleSet;
    unordered_map<int, bool> happyMap;

    int sqareDigitSum(int n) {
        int q, r;
        int sum = 0;
        while (n > 0) {
            q = n / 10;
            r = n - q*10;
            sum += r*r;
            n = q;
        }
        return sum;
    }

    void fillSetToMap(bool state) {
        for (unordered_set<int>::const_iterator itSet = circleSet.begin(); 
             itSet != circleSet.end(); ++itSet) {
            happyMap[*itSet] = state;
        }
        circleSet.clear();
    }

};


