class Solution(object):
    def findDisappearedNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        # mark num at pos(n-1) negative, if n occurs
        for n in nums:
            nums[abs(n) - 1] = -abs(nums[abs(n) - 1])
        return [i + 1 for i, n in enumerate(nums) if n > 0]
