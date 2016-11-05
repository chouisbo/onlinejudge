/**

"   +0 123"
"    010"
"-+1"
"  -0012a42"
"--1"
"a--1"
"+0"
"-a0"
"0"
"012as3"
"123"
"-123"
"2147483647"
"2147483648"
"-2147483647"
"-2147483648"
"-2147483649"


expected

"   +0 123"
"    010"
"-+1"
"  -0012a42"
"--1"
"a--1"
"+0"
"-a0"
"0"
"012as3"
"123"
"-123"
"2147483647"
"2147483648"
"-2147483647"
"-2147483648"
"-2147483649"


**/


int myAtoi(char* str) {
    if (NULL == str) return 0;
    char ch;
    int i = 0;
    int positive = 1;
    long rs = 0;
    
    while (' ' == str[i] && str[i] != '\0') i++;
    
    if ('-' == str[i] || '+' == str[i]) {
        if ('-' == str[i]) positive = 0;
        i++;
    }
    
    while ((ch = str[i++]) != '\0') {
        if (ch < '0' || ch > '9') break;
        else {
            rs = rs * 10 + (ch-'0');
            if (positive  && rs > INT_MAX)  return INT_MAX;
            if (!positive && rs > (unsigned) INT_MIN) return INT_MIN;
        }
    }
    return positive > 0 ? rs : -rs;
    
}
