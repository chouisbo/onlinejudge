#include <ctype.h>
#include <string.h>

bool isPalindrome(char* s) {
    int i=0, j=strlen(s);
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

