class Solution(object):
    def findPeakElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        if n < 0: return None
        if n == 1: return 0
        if nums[0] > nums[1]: return 0
        if nums[-1] > nums[-2]: return n-1
        
        low, high = 1, n-2
        while low <= high:
            mid = int((high - low)/2 + low)
            if nums[mid] > nums[mid-1]:
                if nums[mid] > nums[mid+1]: return mid
                else: low = mid + 1
            else: high = mid - 1
