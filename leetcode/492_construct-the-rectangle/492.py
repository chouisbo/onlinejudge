from math import sqrt

class Solution(object):
    def constructRectangle(self, area):
        """
        :type area: int
        :rtype: List[int]
        """
        root = int(sqrt(area))
        for w in range(root, 0, -1):
            if w * int(area/w) == area:
                return [int(area/w), w]
        return []

if __name__ == "__main__":
    s = Solution()
    print (s.constructRectangle(4))
    print (s.constructRectangle(5))
    print (s.constructRectangle(6))
