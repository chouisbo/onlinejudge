/*
 * Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.
 *
 * Example 1:
 * Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
 * Return 16
 * The two words can be "abcw", "xtfn".
 *
 * Example 2:
 * Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
 * Return 4
 * The two words can be "ab", "cd".
 *
 * Example 3:
 * Given ["a", "aa", "aaa", "aaaa"]
 * Return 0
 * No such pair of words.
 *
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        if (words.size() <= 1) return 0;
        vector<int> vBit, vLen;
        for (auto &x : words) {
            int bit = 0;
            for (auto &l : x) {
                bit = bit | (1 << ('z'-l));
            }
            vBit.push_back(bit);
            vLen.push_back((int) x.length());
            /* printBinaryInteger(bit, 26); */
        }
        int product = 0;
        for (size_t i=0; i < words.size()-1; i++) {
            for (size_t j=i+1; j < words.size(); j++) {
                if (0 == (vBit[i] & vBit[j]) && (vLen[i] * vLen[j] > product)) {
                    product = vLen[i] * vLen[j];
                }
            }
        }
        return product;
    }

    void printBinaryInteger(int n, int length) {
        while (length--) {
            cout << (n & 0x1);
            n >>= 1;
        }
        cout << endl;
    }
};

int main(void) {
    Solution s;
    vector<string> words1 {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
    cout << s.maxProduct(words1) << endl;
    vector<string> words2 {"a", "ab", "abc", "d", "cd", "bcd", "abcd"};
    cout << s.maxProduct(words2) << endl;
    vector<string> words3 {"a", "aa", "aaa", "aaaa"};
    cout << s.maxProduct(words3) << endl;
    return 0;
}

