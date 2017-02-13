bool canConstruct(char* ransomNote, char* magazine) {
    int charMap[26] = {0};
    char *p = magazine;
    while (*p != '\0') {
        charMap[(*p++) - 'a']++;
    }
    for (p = ransomNote; *p != '\0'; p++) {
        charMap[(*p) - 'a']--;
        if (charMap[(*p) - 'a'] < 0) return false;
    }
    return true;
}
