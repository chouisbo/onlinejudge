/*
 * Write a function that takes a string as input and reverse only the vowels of a string.
 *
 * Example 1:
 * Given s = "hello", return "holle".
 *
 * Example 2:
 * Given s = "leetcode", return "leotcede".
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        if (s.length() <= 1) return s;
        size_t i = 0, j = s.length() - 1;
        char swapChar;
        while (true) {
            while (i < j && ! isVowels(s[i])) i++; 
            while (i < j && ! isVowels(s[j])) j--;
            if (j <= i) break;
            swapChar = s[i]; s[i] = s[j]; s[j] = swapChar;
            i++; j--;
        }
        return s;
    }
    bool isVowels(char ch) {
        if ('a' == ch || 'A' == ch ||
            'e' == ch || 'E' == ch ||
            'i' == ch || 'I' == ch ||
            'o' == ch || 'O' == ch ||
            'u' == ch || 'U' == ch) {
            return true;
        }
        return false;
    }
};

int main(void) {
    Solution s;
    cout << s.reverseVowels("hello") << endl;
    cout << s.reverseVowels("leetcode") << endl;
    cout << s.reverseVowels("a.") << endl;
    return 0;
}

