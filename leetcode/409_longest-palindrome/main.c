int longestPalindrome(char* s) {
    int counts[52] = {0};
    for (char *p = s; *p != '\0'; ++p) {
        if (*p >= 'a') {
            counts[(*p - 'a') + 26]++;
        } else {
            counts[(*p - 'A')]++;
        }
    }
    int odd = 0, total = 0;
    for (int i = 0; i < 52; i++) {
        if (counts[i] % 2 == 0) {
            total += counts[i];
        } else {
            total += counts[i] - 1;
            odd = 1;
        }
    }
    return odd + total;
}
