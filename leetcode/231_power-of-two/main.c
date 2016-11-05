bool isPowerOfTwo(int n) {
    if (n < 1)  return false;
    if (1 == n) return true;
    while (n > 1) {
        if (n & 0x1) return false;
        n = n >> 1;
    }
    return true;
}
