class Solution {
public:
    void helper(int &cnt, int &repeat, vector<vector<int>> &grid, int i, int j){
        if(i < 0 || i >= grid.size() || j >= grid[0].size() || j < 0){
            return;
        }
        grid[i][j] = 0;
        cnt++;
        if(i+1 < grid.size() && grid[i+1][j] == 1){
            repeat++;
        }
        if(j+1 < grid[0].size() && grid[i][j+1] == 1){
            repeat++;
        }
        if(i > 0 && grid[i-1][j] == 1){
            repeat++;
        }
        if(j > 0 && grid[i][j-1] == 1){
            repeat++;
        }

        if(i+1 < grid.size() && grid[i+1][j] == 1){
            helper(cnt, repeat, grid, i+1, j);
        }
        if(j+1 < grid[0].size() && grid[i][j+1] == 1){
            helper(cnt, repeat, grid, i, j+1);
        }
        if(i > 0 && grid[i-1][j] == 1){
            helper(cnt, repeat, grid, i-1, j);
        }
        if(j > 0 && grid[i][j-1] == 1){
            helper(cnt, repeat, grid, i, j-1);
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        /*
        1 -> 4
        2 -> 4*2-1 
        3 -> 4*3 - 2

        n -> 4 * n - (n-1) -> 4n-n+1 -> 3n+1
        k -> 3k+1

        4*count - minus repeat perimeter
        
        */

        int ret = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 1){
                    int cnt = 0, repeat = 0;
                    helper(cnt, repeat, grid, i, j);
                    ret += (4*cnt - repeat * 2);
                }
            }
        }

        return ret;
    }
};