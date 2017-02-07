char findTheDifference(char* s, char* t) {
    char target = 0;
    for (int i = 0; *(s+i) != '\0'; i++) {
        target ^= *(s+i);
    }
    for (int i = 0; *(t+i) != '\0'; i++) {
        target ^= *(t+i);
    }
    return target;
}
