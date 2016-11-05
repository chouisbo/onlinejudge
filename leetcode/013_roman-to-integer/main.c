int romanToInt(char* s) {
    if (NULL == s || *s == '\0') return 0;
    char *p  = s;
    int val  = 0;
    char lvl = 'M';
    while (*p != '\0') {
        if (*p == 'I') {
            if (lvl == 'V') {
                val += 1;
            } else {
                if (*(p+1) == 'V') {
                    val += 4; p++;
                } else if (*(p+1) == 'X') {
                    val += 9; p++;
                } else {
                    val += 1;
                }
            }
        } else if (*p == 'X') {
            if (lvl == 'L') {
                val += 10;
            } else {
                if (*(p+1) == 'L') {
                    val += 40; p++;
                } else if (*(p+1) == 'C') {
                    val += 90; p++;
                } else {
                    val += 10;
                }
            }
        } else if (*p == 'C') {
            if (lvl == 'D') {
                val += 100;
            } else {
                if (*(p+1) == 'D') {
                    val += 400; p++;
                } else if (*(p+1) == 'M') {
                    val += 900; p++;
                } else {
                    val += 100;
                }
            }
        } else if (*p == 'V') {
            val += 5;
            lvl = 'V';
        } else if (*p == 'L') {
            val += 50;
            lvl = 'L';
        } else if (*p == 'D') {
            val += 500;
            lvl = 'D';
        } else if (*p == 'M') {
            val += 1000;
        }
        p++;
    }
    return val;
}
