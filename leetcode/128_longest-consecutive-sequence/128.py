class Solution(object):

    def find(self, s, x):
        if s[x] < 0: 
            return x
        else:
            s[x] = self.find(s, s[x])
            return s[x]


    def union(self, s, a, b):
        root1, root2 = self.find(s, a), self.find(s, b)
        if root1 == root2: return
        if s[root2] < s[root1]:
            s[root1] = root2
        else:
            if s[root1] == s[root2]:
                s[root1] -= 1
            s[root2] = root1


    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums: return 0
        minNum = min(nums)
        # print ("nums => %s, minNum => %d" % (nums, minNum))
        for i in range(len(nums)):
            nums[i] -= minNum
        # print ("nums => %s" % nums)
        numsSet, s, c = set(nums), {}, {}
        for n in nums: s[n] = -1
        for n in nums:
            if n-1 in numsSet:
                self.union(s, n, n-1)
            if n+1 in numsSet:
                self.union(s, n, n+1)
        for n in numsSet:
            k = self.find(s, n)
            if k not in c: c[k] = 0
            c[k] += 1
        # print (c)
        return max(c.values())


if __name__ == '__main__':
    s = Solution()
    print (s.longestConsecutive([])) # 0
    print (s.longestConsecutive([100, 4, 200, 1, 3, 2])) # 4
    print (s.longestConsecutive([1, 3, 5, 2, 4])) # 5
    print (s.longestConsecutive([0, 0])) # 1
    print (s.longestConsecutive([4,0,-4,-2,2,5,2,0,-8,-8,-8,-8,-1,7,4,5,5,-4,6,6,-3])) # 5
