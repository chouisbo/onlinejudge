public class Solution {
    public int totalHammingDistance(int[] nums) {
        int total = 0, n = nums.length;
        for (int i = 0; i < 32; i++) {
            int nOnes = 0;
            for (int j = 0; j < n; j++) {
                // if ((nums[j] & (1 << i)) > 0) nOnes++;
                nOnes += (nums[j] >> i) & 0x1;
            }
            total += nOnes * (n - nOnes);
        }
        return total;
    }
}
