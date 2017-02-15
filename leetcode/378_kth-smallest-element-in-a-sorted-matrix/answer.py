import heapq

class Solution(object):
    def kthSmallest(self, matrix, k):
        """
        :type matrix: List[List[int]]
        :type k: int
        :rtype: int
        """
        if k <= 0: return None
        if 1 == k: return matrix[0][0]
        heap, n = [], len(matrix)
        initRow = int(k/n) + 1
        if initRow > n: initRow = n
        for i in range(initRow):
            for j in range(n):
                if len(heap) < k:
                    heapq.heappush(heap, -matrix[i][j])
                elif matrix[i][j] < -heap[0]: heapq.heapreplace(heap, -matrix[i][j])
                else: pass
        col = n
        for i in range(initRow, n):
            j = 0
            while j < col:
                if matrix[i][j] < -heap[0]: 
                    heapq.heapreplace(heap, -matrix[i][j])
                else: col = j
                j += 1
        return -heap[0]
        

if __name__ == "__main__":
        s = Solution()
        matrix = [[1,5,9],[10,11,13],[12,13,15]]
        print (s.kthSmallest(matrix, 8))
        print (s.kthSmallest(matrix, 3))
        print (s.kthSmallest(matrix, 1))
        print (s.kthSmallest(matrix, 5))
        print (s.kthSmallest(matrix, 9))

