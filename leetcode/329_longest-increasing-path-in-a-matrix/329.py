class Solution(object):
    def longestIncreasingPath(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        
        if not matrix or not matrix[0]: return 0
        M, N = len(matrix), len(matrix[0])
        dp = [[0] * N for i in range(M)]

        def dfs(i, j):
            if 0 == dp[i][j]:
                dp[i][j] = 1 + max(
                    dfs(i-1, j) if i and matrix[i][j] > matrix[i-1][j] else 0,
                    dfs(i+1, j) if i < M-1 and matrix[i][j] > matrix[i+1][j] else 0,
                    dfs(i, j-1) if j and matrix[i][j] > matrix[i][j-1] else 0,
                    dfs(i, j+1) if j < N-1 and matrix[i][j] > matrix[i][j+1] else 0
                )
            return dp[i][j]

        return max(dfs(x, y) for x in range(M) for y in range(N))

'''
Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

nums = [
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
Return 4
The longest increasing path is [1, 2, 6, 9].

Example 2:

nums = [
  [3,4,5],
  [3,2,6],
  [2,2,1]
]
Return 4
The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
'''

if __name__ == '__main__':
    s = Solution()
    print (s.longestIncreasingPath([[9,9,4], [6,6,8], [2,1,1]]))
    print (s.longestIncreasingPath([[3,4,5], [3,2,6], [2,2,1]]))
