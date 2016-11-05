#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() >= 2) {
            int p = 0;
            int maxP = 0;
            int lowest = prices[0];
            for (size_t i=1; i<prices.size(); ++i) {
                p = prices[i] - lowest;
                if (p > maxP) maxP = p;
                if (p < 0) lowest = prices[i];
            }
            return maxP;
        } else {
            return 0;
        }
    }
};


int main(void) {
    vector<int> prices = {-2,1,-3,4,-1,2,1,-5,4};
    Solution s;
    cout << s.maxProfit(prices) << endl; 
    return 0;
}
