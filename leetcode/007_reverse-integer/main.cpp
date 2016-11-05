
#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        if (0 == x) return 0;
        long long sum = 0;
        bool signPositive = true;
        if (x < 0) {
            signPositive = false;
            x = -1 * x;
        }
        while (x != 0) {
            int r = x % 10;
            sum = sum*10 + r;
            if (sum > INT_MAX || sum < INT_MIN) {
                return 0;
            }
            x = x / 10;
        }
        if (signPositive) return (int) sum;
        else return -1 * (int) sum;
    }
};


int main(void) {
    Solution s;
    cout << 0 << " reverse => " << s.reverse(0) << endl;
    cout << 100 << " reverse => " << s.reverse(100) << endl;
    cout << -100 << " reverse => " << s.reverse(-100) << endl;
    cout << 10000003 << " reverse => " << s.reverse(10000003) << endl;
    cout << -10000003 << " reverse => " << s.reverse(-10000003) << endl;
    cout << 1000000003 << " reverse => " << s.reverse(1000000003) << endl;
    cout << -1000000003 << " reverse => " << s.reverse(-1000000003) << endl;

    return 0;
}
