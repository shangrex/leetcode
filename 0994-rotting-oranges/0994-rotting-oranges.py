class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        w, h = len(grid[0]), len(grid)
        q = []
        hasFreshOrange = False
        for i, row in enumerate(grid):
            for j, orange in enumerate(row):
                if orange == 2:
                    q.append((i, j))
                if orange == 1:
                    hasFreshOrange = True
        # [[1]]
        # edge case: no rotten orange
        if not q:
            if hasFreshOrange: 
                return -1
            return 0

        minutes = -1
        while q:
            sz = len(q)
            for _ in range(sz):
                i, j = q[0]
                q.pop(0)
                
                # out of boundary / empty
                if i + 1 < h and grid[i+1][j] == 1: 
                    q.append((i+1, j))
                    grid[i+1][j] = 2
                if i - 1 >= 0 and grid[i-1][j] == 1: 
                    q.append((i-1, j))
                    grid[i-1][j] = 2
                if j + 1 < w and grid[i][j+1] == 1: 
                    q.append((i, j+1))
                    grid[i][j+1] = 2
                if j - 1 >= 0 and grid[i][j-1] == 1: 
                    q.append((i, j-1))
                    grid[i][j-1] = 2
            minutes += 1
        
        # edge case: cannot rot all the orange
        for i, row in enumerate(grid):
            for j, orange in enumerate(row):
                if orange == 1:
                    return -1
        
        return minutes

                