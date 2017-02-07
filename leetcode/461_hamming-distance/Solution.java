public class Solution {

    public int hammingDistance(int x, int y) {

        int n = x ^ y;
        int nOnes = 0;
        while (n != 0) {
            n &= n - 1;
            nOnes++;
        }
        return nOnes;

    }

}
