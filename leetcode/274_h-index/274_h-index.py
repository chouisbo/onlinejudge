class Solution(object):
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        if not citations: return 0
        return max(min(i+1, c) for i, c in enumerate(sorted(citations, reverse=True)))

if __name__ == "__main__":
    s = Solution()
    print s.hIndex([1,1,3,6,7,10,7,1,8,5,9,1,4,4,3])
    print s.hIndex([3, 0, 6, 1, 5])
    print s.hIndex([100])
    print s.hIndex([1])
    print s.hIndex([])
