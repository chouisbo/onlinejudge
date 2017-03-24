#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
#include <map>


using namespace std;


class Solution {
public:
    int numSquares(int n) {
        if (n <= 0) return 0;
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for (int i=1; i<=n; i++) {
            for (int j=1; j*j <=i; j++) {
                dp[i] = min(dp[i], dp[i-j*j] + 1);
            }
        }
        return dp[n];
    }

    pair<int, int> numSquaresPair(int n) {
        if (n < 0) return pair<int, int>(0, -1);
        if (n < data.size()) return data[n];
        int initSize = data.size();
        data.resize(n+1, pair<int, int>(INT_MAX, 0));
        if (0 == initSize) {
            data[0] = pair<int, int>(0, 0);
        }
        for (int i = initSize; i <= n; i++) {
            for (int j = 1; j*j <= i; j++) {
                if ( (data[i-j*j].first + 1) < data[i].first ) {
                    data[i].first  = data[i-j*j].first + 1;
                    data[i].second = i-j*j;
                }
            }
        }
        return data[n];
    }

    vector<int> soluteNumSquares(int n) {
        int size = numSquaresPair(n).first;
        vector<int> rs(size, 0);
        for (int i = 0; i < size; i++) {
            rs[i] = n - data[n].second;
            n = data[n].second;
        }
        return rs;
    }

private:
    vector<pair<int, int> > data;
};

void outputSolution(const vector<int> &s) {
    for (auto &x : s) cout << x << " + ";
}


int main(void) {

    Solution s;
    for (int i = 0; i <= 16; i++) {
        cout << i << " => " << s.numSquares(i) << ',' << s.numSquaresPair(i).first << " : ";
        outputSolution(s.soluteNumSquares(i));
        cout << endl;
    }
    cout << 7168 << " => " << s.numSquares(7168) << ',' << s.numSquaresPair(7168).first << " : ";
    outputSolution(s.soluteNumSquares(7168));
    cout << endl;
    
    return 0;
}

