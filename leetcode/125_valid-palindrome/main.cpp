#include <ctype.h>

class Solution {
public:
    bool isPalindrome(string s) {
        size_t i=0, j=s.length();
        if (0 == j--) return true;
        while (i < j) {
            if (0 == isalnum(s[i])) { i++; continue; }
            if (0 == isalnum(s[j])) { j--; continue; } 
            if (tolower(s[i]) == tolower(s[j])) {
                i++; j--;
            } else return false;
        }
        return true;
    }
};
