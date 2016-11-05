#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <fstream>

using namespace std;

#define MIN_DOUBLE_PRECISION 

class Solution {
public:

    double _pow_positive(double x, int n) {
        if (0 == n) return 1.0;
        if (1 == n) return x;
        if (2 == n) return x*x;

        int k = n/2;
        double y = _pow_positive(x, k);

        if (2*k < n) {
            return y*y*x;
        } else {
            return y*y;
        }
    }

    double myPow(double x, int n) {
        if (0 == n) return 1.0;
        bool minus = false;
        if (n < 0) {
            n *= -1;
            minus = true;
        }
        if (minus) return 1.0/_pow_positive(x, n);
        else return _pow_positive(x, n);
    }
};

int main(int argc, const char* argv[]) {
    
    Solution s;
    cout << s.myPow(3, 0) << endl;
    cout << s.myPow(3, 1) << endl;
    cout << s.myPow(3, 2) << endl;
    cout << s.myPow(3, 3) << endl;
    cout << s.myPow(3, -1) << endl;
    cout << s.myPow(3, -2) << endl;
    cout << s.myPow(3, -3) << endl;

    cout << s.myPow(4.70975, -6) << endl;

    return 0;
}
