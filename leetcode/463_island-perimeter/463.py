class Solution(object):
    def islandPerimeter(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        row = len(grid)
        if row <= 0: return 0
        col = len(grid[0])
        if col <= 0: return 0
        
        p = 0
        for i in range(row):
            for j in range(col):
                if grid[i][j] == 1:
                    # up
                    if i - 1 < 0 or grid[i-1][j] == 0: p += 1
                    # down
                    if i + 1 >= row or grid[i+1][j] == 0: p += 1
                    # left
                    if j - 1 < 0 or grid[i][j-1] == 0: p += 1
                    # right
                    if j + 1 >= col or grid[i][j+1] == 0: p += 1
        return p
