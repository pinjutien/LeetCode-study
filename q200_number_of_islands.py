# BFS
# ref: http://www.jiuzhang.com/solutions/number-of-islands/

class Solution(object):


    def check(self, row, col, m, n):
        # 1. row and col are in the valid index range
        # 2. not visit before
        # 3. grid[row][col] = 1
        if (row >= 0) and (row < m) and (col >= 0) and (col < n) and (is_visit[row][col] == 0) and (grid[row][col] == 1):
            return True
        return False


    def DFS(self, x, y, is_visit):
        explored_row = [1, 0, 0, -1]
        explored_col = [0, 1, -1, 0]

        for k in range(len(explored_row)):
            x_temp = x + explored_row[k]
            y_temp = y + explored_col[k]
            if (self.check(x_temp, y_temp, m, n)):
                is_visit[x_temp][y_temp] = 1
                DFS(x_temp, y_temp)
                
    
    def numIslands(self, grid):
        m = grid.shape[0]
        n = grid.shape[1]
        
        if (m == 0): return 0

        is_visit = np.zeros([m, n])

        count = 0
        for i in range(m):
            for j in range(n):
                if(self.check(i, j, m, n)):
                    is_visit[i, j] = True
                    self.DFS(i, j, is_visit)
                    count += 1

        return count
