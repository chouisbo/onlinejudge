class Solution(object):
    # Execeed Time Limit
    def minMoves(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        m, n, nums = 0, len(nums), sorted(nums)
        while nums[0] != nums[-1]:
            i = n - 1
            while nums[i] == nums[-1]: i -= 1
            k = nums[i+1] - nums[i]
            for j in range(n):
                if j != i+1: nums[j] += k
            m += k
        return m, nums


if __name__ == '__main__':
    s = Solution()
    print (s.minMoves([1,2,3,4]))
    print (s.minMoves([3,3,3,4]))
    print (s.minMoves([3,3,6,6]))
