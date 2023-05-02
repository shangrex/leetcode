class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0)return 0;
        int n = grid.size();
        int m = grid[0].size();
        // 0 means not visited
        // 1 means visited
        vector<vector<int> >visited(n, vector<int>(m, 0));
        int rst = 0;
        for(int i = 0;i < n; i++){
            for(int j = 0; j < m; j++){
                if(visited[i][j] == 0 && grid[i][j] == '1'){
                    rst++;
                    dfs(i, j, visited, grid);
                }
            }
        }
        return rst;
    }
    
    void dfs(int row, int col, vector<vector<int>> &visited, vector<vector<char>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        visited[row][col] = 1;
        // down
        if(row+1 < n){
            if(grid[row+1][col] == '1' && visited[row+1][col] == 0){
                dfs(row+1, col, visited, grid);
            }            
        }
        // up
        if(row-1 >= 0){
            if(grid[row-1][col] == '1' && visited[row-1][col] == 0){
                dfs(row-1, col, visited, grid);
            }
        }
        // left
        if(col-1 >= 0){
            if(grid[row][col-1] == '1' && visited[row][col-1] == 0){
                dfs(row, col-1, visited, grid);
            }
        }
        // right
        if(col+1 < m){
            if(grid[row][col+1] == '1' && visited[row][col+1] == 0){
                dfs(row, col+1, visited, grid);
            }
        }
    }
};