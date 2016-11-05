#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() >= 2) {
            int lowest = prices[0];
            int previous = prices[0];
            int profit = 0;
            for (size_t i=1; i<prices.size(); ++i) {
                if (prices[i] < previous) {
                    profit += previous - lowest;
                    lowest = prices[i];
                }
                previous = prices[i];
            }
            profit += previous - lowest;
            return profit;
        } else {
            return 0;
        }
    }
};


int main(void) {
    vector<int> prices = {2,1,3,4,1,2,1,5,4};
    Solution s;
    cout << s.maxProfit(prices) << endl; 
    return 0;
}
