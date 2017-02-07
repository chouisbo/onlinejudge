public class Solution {
    public boolean validUtf8(int[] data) {
        int n = data.length, i = 0;
        while (i < n) {
            int head = data[i] & 0xff, mask = 0x80, nOnes = 0;
            while ((head & mask) != 0) {
                mask >>= 1;
                nOnes++;
                if (nOnes >= 5) return false;
            }
            if (0 == nOnes) {
                i++;
            } else if (1 == nOnes) {
                return false;
            } else {
                if (i + nOnes > n) return false;
                for (int j = 1; j < nOnes; j++) {
                    if ((data[i+j] & 0xc0) != 0x80) return false;
                }
                i += nOnes;
            }
        }
        return true;
    }

	public static void main(String[] args) {
		Solution s = new Solution();
		// int[] data = {197, 130, 1};
        int[] data = {237};
		System.out.println(s.validUtf8(data));
	}
}
