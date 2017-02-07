class Solution(object):

    def hammingDistance(self, x, y):

        """
        :type x: int
        :type y: int
        :rtype: int
        """
        
        nOnes, n = 0, x ^ y;
        while n != 0:
            n = n & (n -1)
            nOnes += 1
        return nOnes

