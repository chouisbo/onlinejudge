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


    def findOrder(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: List[int]
        """
        for el in prerequisites:
            if el[0] == el[1]: return []
        outcomingMap = self.getOutcomingMap(prerequisites)
        if len(outcomingMap) >= numCourses: return []
        incomingCountMap = self.getIncomingCountMap(numCourses, prerequisites)
        L, S = [], set([k for k, v in incomingCountMap.items() if v == 0])
        while S:
            n = S.pop()
            if n in outcomingMap:
                for m in outcomingMap[n]:
                    incomingCountMap[m] -= 1
                    if 0 == incomingCountMap[m]: S.add(m)
            L.append(n)
        if len(L) != numCourses: return []
        return L


if __name__ == '__main__':
    s = Solution()
    print (s.findOrder(2, [[1,0]]))
    print (s.findOrder(4, [[1,0],[2,0],[3,1],[3,2]]))
    print (s.findOrder(2, [[1,0], [0,1]]))
    print (s.findOrder(3, [[1,0], [1, 2], [0, 2]]))