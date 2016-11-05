
char* reverseString(char* s) {
    if (NULL == s) return NULL;
    int len = (int) strlen(s); char ch;
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        // swap s[i] and s[j]
        ch = s[i]; s[i] = s[j]; s[j] = ch;
    }
    return s;
}


