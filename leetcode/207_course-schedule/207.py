class Solution(object):

    def getIncomingCountMap(self, numCourses, prerequisites):
        incomingCountMap = {}
        for i in range(numCourses):
            incomingCountMap[i] = 0
        for el in prerequisites:
            incomingCountMap[el[0]] += 1
        return incomingCountMap


    def getOutcomingMap(self, prerequisites):
        outcomingMap = {}
        for el in prerequisites:
            if el[1] not in outcomingMap:
                outcomingMap[el[1]] = []
            outcomingMap[el[1]].append(el[0])
        return outcomingMap


    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        for el in prerequisites:
            if el[0] == el[1]: return False
        outcomingMap = self.getOutcomingMap(prerequisites)
        if len(outcomingMap) >= numCourses: return False
        incomingCountMap = self.getIncomingCountMap(numCourses, prerequisites)
        L, S = [], set([k for k, v in incomingCountMap.items() if v == 0])
        while S:
            n = S.pop()
            if n in outcomingMap:
                for m in outcomingMap[n]:
                    incomingCountMap[m] -= 1
                    if 0 == incomingCountMap[m]: S.add(m)
            L.append(n)
        return len(L) == numCourses


if __name__ == '__main__':
    s = Solution()
    print (s.canFinish(2, [[1,0]]))
    print (s.canFinish(2, [[1,0], [0,1]]))
    print (s.canFinish(3, [[1,0], [1, 2], [0, 2]]))