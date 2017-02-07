class Solution(object):
    def totalHammingDistance(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n, isAllZero, dis = len(nums), True, 0
        for num in nums:
            if num != 0: 
                isAllZero = False
                break
        while not isAllZero:
            nOne, nZero, isAllZero = 0, 0, True
            for i in xrange(n):
                if nums[i] & 0x1: nOne += 1
                else: nZero += 1
                nums[i] = nums[i] >> 1
                if isAllZero and nums[i] != 0: isAllZero = False
            dis += nOne * nZero
        return dis
