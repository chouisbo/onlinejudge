
// https://www.hrwhisper.me/leetcode-power-four/
// power of four must be a power of two
// n & (n-1) == 0 => power of two
// power of two & 0x55555555 [0101010101] != 0


bool isPowerOfFour(int num) {
    return num > 0 && (num & (num - 1)) ==0  && (num & 0x55555555) !=0;
}
