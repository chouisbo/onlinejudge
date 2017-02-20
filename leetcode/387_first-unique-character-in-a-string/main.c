int firstUniqChar(char* s) {
    int counts[26] = {0};
    for (char *p = s; *p != '\0'; p++) {
        counts[(*p - 'a')]++;
    }
    for (char *p = s; *p != '\0'; p++) {
        if (counts[(*p - 'a')] == 1) {
            return p - s;
        }
    }
    return -1;
}
