class Solution(object):
    def numberOfBoomerangs(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        count, n = 0, len(points)
        for i in range(n):
            distMap = {}
            for j in range(n):
                dist = (points[i][0] - points[j][0]) ** 2 + (points[i][1] - points[j][1]) ** 2
                if dist not in distMap: distMap[dist] = 0
                count += distMap[dist] * 2
                distMap[dist] += 1
        return count


if __name__ == '__main__':
    s = Solution()
    print (s.numberOfBoomerangs([[0,0],[1,0],[2,0]]))

