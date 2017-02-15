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
        for i in range(n):
            heapq.heappush(heap, (matrix[0][i], 0, i))
        for i in range(k-1):
            item = heapq.heappop(heap)
            row, col = item[1]+1, item[2]
            if row < n: heapq.heappush(heap, (matrix[row][col], row, col))
        return heap[0][0]
        

if __name__ == "__main__":
        s = Solution()
        matrix = [[1,5,9],[10,11,13],[12,13,15]]
        print (s.kthSmallest(matrix, 8))
        print (s.kthSmallest(matrix, 3))
        print (s.kthSmallest(matrix, 1))
        print (s.kthSmallest(matrix, 5))
        print (s.kthSmallest(matrix, 9))

