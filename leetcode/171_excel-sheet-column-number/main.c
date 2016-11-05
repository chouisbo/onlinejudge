int titleToNumber(char* s) {
    int   n = 0;
    char *p = s;
    while (*p != '\0') {
        n = 26 * n + (*p++ - 'A' + 1);
    }
    return n;
}
