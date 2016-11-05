#include <iostream>
#include <cmath>

using namespace std;

class Solution {

public:
    bool isPowerOfThree(int n) {
        double rs = log((double)n) / log(3.0);
        return abs(rs - round(rs)) < 1e-10;
    }
};


int main(void) {
    Solution s;
    for (int i = 0; i < 2000000000; i++) {
        if (s.isPowerOfThree(i)) {
            cout << i << " is a power of three" << endl;
        }
    }
}
