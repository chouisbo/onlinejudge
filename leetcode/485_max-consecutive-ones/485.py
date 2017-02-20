class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        maxlen, curlen = 0, 0
        for num in nums:
            if num == 1: curlen += 1
            else:
                maxlen = max(maxlen, curlen)
                curlen = 0
        return max(maxlen, curlen)
        
