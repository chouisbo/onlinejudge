/* 
 * Given a non negative integer number num. 
 * For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's 
 * in their binary representation and return them as an array.
 *
 * Example:
 * For num = 5 you should return [0,1,1,2,1,2].
 *
 * Follow up:
 * It is very easy to come up with a solution with run time O(n*sizeof(integer)). 
 * But can you do it in linear time O(n) /possibly in a single pass?
 * Space complexity should be O(n).
 * Can you do it like a boss? 
 * Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
 *
 * Hint:
 * You should make use of what you have produced already.
 * Divide the numbers in ranges like [2-3], [4-7], [8-15] and so on. 
 * And try to generate new range from previous.
 * Or does the odd/even status of the number help you in calculating the number of 1s?
 */

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        if (0 == num) return vector<int> {0};
        if (1 == num) return vector<int> {0, 1};
        int power = almostPowerOfTwo(num);
        vector<int> rs = countBitsForPowerOfTwo(power);
        for (int i = 1 << power, j = 0; i <= num; i++, j++) {
            rs.push_back(rs[(size_t) j]+1);
        }
        return rs;
    }
    vector<int> countBitsForPowerOfTwo(int num) {
        vector<int> rs = {0, 1};
        while (--num) {
            size_t len = rs.size();
            for (size_t i=0; i < len; i++) {
                rs.push_back(rs[i] + 1);
            }
        }
        return rs;
    }
    int almostPowerOfTwo(int num) {
        int shift = 0;
        while ((1 << shift) <= num) {
            shift++;
        }
        return shift-1;
    }
};

int main(int argc, const char *argv[]) {
    Solution s;
    for (auto &x: s.countBits(atoi(argv[1]))) {
        cout << x << ", ";
    }
    cout << endl;
    return 0;
}

