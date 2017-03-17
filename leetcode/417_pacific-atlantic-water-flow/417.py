class Solution(object):
    def pacificAtlantic(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[List[int]]
        """
        if not matrix: return []
        M, N = len(matrix), len(matrix[0])
        pacific_queue = [(0, x) for x in range(N)] + [(x, 0) for x in range(1, M)]
        atlantic_queue = [(M-1, x) for x in range(N)] + [(x, N-1) for x in range(M-1)]
        return [[coord[0], coord[1]] for coord in (self.bfs(matrix, M, N, pacific_queue) & self.bfs(matrix, M, N, atlantic_queue))]


    def bfs(self, matrix, M, N, queue):
        coordSet = set()
        while queue:
            (x, y) = queue.pop(0)
            coordSet.add((x, y))
            if x > 0 and matrix[x-1][y] >= matrix[x][y] and (x-1, y) not in coordSet:
                queue.append((x-1, y))
            if x < M-1 and matrix[x+1][y] >= matrix[x][y] and (x+1, y) not in coordSet:
                queue.append((x+1, y))
            if y > 0 and matrix[x][y-1] >= matrix[x][y] and (x, y-1) not in coordSet:
                queue.append((x, y-1))
            if y < N-1 and matrix[x][y+1] >= matrix[x][y] and (x, y+1) not in coordSet:
                queue.append((x, y+1))
        return coordSet


def test_01():
    '''
    Given the following 5x5 matrix:

      Pacific ~   ~   ~   ~   ~ 
           ~  1   2   2   3  (5) *
           ~  3   2   3  (4) (4) *
           ~  2   4  (5)  3   1  *
           ~ (6) (7)  1   4   5  *
           ~ (5)  1   1   2   4  *
              *   *   *   *   * Atlantic

    Return:

    [[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix).
    '''
    s = Solution()
    matrix = [
        [1, 2, 2, 3, 5],
        [3, 2, 3, 4, 4],
        [2, 4, 5, 3, 1],
        [6, 7, 1, 4, 5],
        [5, 1, 1, 2, 4]
    ]
    print (s.pacificAtlantic(matrix))


if __name__ == '__main__':
    test_01()

