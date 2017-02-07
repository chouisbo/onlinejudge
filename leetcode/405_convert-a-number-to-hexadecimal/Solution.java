public class Solution {
    public String toHex(int num) {
        if (0 == num) return "0";
        int mask = 0xf0000000, n = 7;
        String result = "";
        boolean headingZero = true;
        while (mask != 0) {
            int rc = (num & mask) >>> (4*n);
            mask >>>= 4; n--;
            if (0 == rc && headingZero) {
                continue;
            } else {
                headingZero = false;
            }
            if (rc > 9) {
                result += (char)('a' + rc - 10);
            } else {
                result += (char)('0' + rc);
            }
        }
        return result.toString();
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.toHex(26));
    }
}
