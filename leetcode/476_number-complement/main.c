int findComplement(int num) {
    int n = num, i = 0;
    while (n != 0) {
        n >>= 1;
        i++;
    }
    return num ^ ((1 << i)-1);
}
