class Solution {
public:
    int dfs(vector<vector<int>> &grid, int i, int j, int cnt){
        int h = grid.size();
        int w = grid[0].size();
        grid[i][j] = 0;
        // cout << i << " " << j << endl ;
        int tmp_cnt = cnt;
        cnt++;
        if(i+1 < h && grid[i+1][j] == 1)cnt = dfs(grid, i+1, j, cnt);
        if(j+1 < w && grid[i][j+1] == 1)cnt = dfs(grid, i, j+1, cnt);
        if(i > 0 && grid[i-1][j] == 1)cnt = dfs(grid, i-1, j, cnt);
        if(j > 0 && grid[i][j-1] == 1)cnt = dfs(grid, i, j-1, cnt);
        // cout << "cnt "<< cnt << endl;
        return cnt;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rst = 0;
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    rst = max(rst, dfs(grid, i, j, 0));
                    // cout << "rst " << rst << endl;
                }
            }
        }
        return rst;
    }
};