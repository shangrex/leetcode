class Solution {
public:
    
    void dfs(vector<vector<char>> &grid, int i, int j){
        grid[i][j] = '0';
        int row = grid.size();
        int col = grid[0].size();
        
        if(i-1 >= 0 && grid[i-1][j] == '1'){
            dfs(grid, i-1, j);
        }
        if(i+1 < row && grid[i+1][j] == '1'){
            dfs(grid, i+1, j);
        }
        if(j-1 >= 0 && grid[i][j-1] == '1'){
            dfs(grid, i, j-1);
        }
        if(j+1 < col && grid[i][j+1] == '1'){
            dfs(grid, i, j+1);
        }
        
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int cnt = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == '1'){
                    cnt++;
                    dfs(grid, i, j);
                }
            }
        }
        return cnt;
    }
};