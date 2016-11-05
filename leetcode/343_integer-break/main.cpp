/*
 * Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.
 *
 * For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).
 *
 * Note: you may assume that n is not less than 2.
 *
 * Hint:
 *
 * There is a simple O(n) solution to this problem.
 * You may check the breaking results of n ranging from 7 to 10 to discover the regularities.
 *
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        if (n <= 2) return 1;
        if (3 == n) return 2;

        int base  = 3; 
        int power = n / base;
        int remain = n - power * base;

        switch (remain) {
            case 0: return intPow(base, power);
            case 1: return intPow(base, power-1) * (base+1);
            default: return intPow(base, power) * remain;
        }
    }

    int intPow(int base, int exp) {
        int rs = 1;
        while (exp--) rs *= base;
        return rs;
    }
};

int main(void) {
    Solution s;
    for (int i=6; i <= 16; i++) {
        cout << "integerBreak of " << i << " is " << s.integerBreak(i) << endl;
    }
    return 0;
}

