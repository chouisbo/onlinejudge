/*
 * The gray code is a binary numeral system where two successive values differ in only one bit.
 *
 * Given a non-negative integer n representing the total number of bits in the code, 
 * print the sequence of gray code. A gray code sequence must begin with 0.
 *
 * For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
 *
 * 00 - 0
 * 01 - 1
 * 11 - 3
 * 10 - 2
 * Note:
 * For a given n, a gray code sequence is not uniquely defined.
 *
 * For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.
 *
 * For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printVecInt(vector<int> vec) {
    for (auto &x : vec) {
        cout << x << ", ";
    }
    cout << endl;
}

class Solution {
public:
    vector<int> grayCode(int n) {
        if (1 == n) return vector<int> {0, 1};
        else if (0 == n) return vector<int> {0};
        else if (n < 0) return vector<int> {};
        
        vector<int> last = grayCode(n-1);
        vector<int> next;
        const int DELTA = 1 << (n-1);
        for (vector<int>::const_reverse_iterator it = last.rbegin();
             it != last.rend(); it++) {
            next.push_back(*it + DELTA);
        }
        last.resize(last.size() * 2);
        move_backward(next.begin(), next.end(), last.end());
        return last;
    }
};

int main(void) {
    Solution s;
    printVecInt(s.grayCode(2));
    return 0;
}

