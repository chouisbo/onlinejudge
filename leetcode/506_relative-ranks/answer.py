class Solution(object):
    def findRelativeRanks(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        sort = sorted(nums)[::-1]
        rank = ["Gold Medal", "Silver Medal", "Bronze Medal"] + list(map(str, range(4, len(nums)+1)))
        return list(map(dict(zip(sort, rank)).get, nums))

if __name__ == "__main__":
    s = Solution()
    print (s.findRelativeRanks([1,4,5,3,2]))
