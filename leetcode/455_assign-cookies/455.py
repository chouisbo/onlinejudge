import bisect

class Solution(object):
    def findContentChildren(self, g, s):
        """
        :type g: List[int]
        :type s: List[int]
        :rtype: int
        """
        n, g, s = 0, sorted(g), sorted(s)
        while s and g:
            if g[-1] <= s[-1]:
                s.pop()
                n += 1
            g.pop()
        return n
        

if __name__ == "__main__":
    s = Solution()
    print (s.findContentChildren([1,2,3], [1,1]))
    print (s.findContentChildren([1,2], [1,2,3]))
