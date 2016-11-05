bool isUgly(int num) {
    int n = num;
    if (n <= 0) return false;
    while (0 == n%5) n /= 5;
    while (0 == n%3) n /= 3;
    while (0 == n%2) n /= 2;
    return 1 == n;
}
