/* Use Binary Searching to find the solution */

int mySqrt(int x) {
    if (x < 0) return -1; // Input Error
    if (x <= 1) return x; // 0 -> 0, 1->1
    long l = 1, h = x/2, m;
    while (l < h) {
        m = (h - l)/2 + l;
        if (m * m == x) {
            return m;
        } else if (m * m > x) {
            h = m - 1;
        } else {
            l = m + 1;
        }
    }
    if (l * l <= x) return l;
    else return l-1;
}
