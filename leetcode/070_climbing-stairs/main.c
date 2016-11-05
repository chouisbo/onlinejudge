int climbStairs(int n) {
    if (n < 1)  return 0;
    if (1 == n) return 1;
    if (2 == n) return 2;
    int a = 1;
    int b = 2;
    int i, tmp;
    for (i=3; i<n; i++) {
        tmp = b;
        b += a;
        a = tmp;
    }
    return a+b;
}

