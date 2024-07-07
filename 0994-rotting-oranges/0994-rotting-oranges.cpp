class Solution {
public:
    /*
    Approach 1.
    step 1. search rotten and bfs
    step 2. chekc if there is still fresh orange
    step 3. 
    */

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int rst = INT_MAX;
        int day = 0;
        
        queue<pair<int, int>> q;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }
        
        while(!q.empty()){
            int level = q.size();
            day++;
            for(int i = 0; i < level; i++){
                pair<int, int> t = q.front();
                q.pop();
                if(t.first > 0 && grid[t.first-1][t.second] == 1) {
                    q.push({t.first-1, t.second});
                    grid[t.first-1][t.second] = 2;
                }
                if(t.first < n-1 && grid[t.first+1][t.second] == 1){
                    q.push({t.first+1, t.second});
                    grid[t.first+1][t.second] = 2;
                }
                if(t.second > 0 && grid[t.first][t.second - 1] == 1){
                    q.push({t.first, t.second-1});
                    grid[t.first][t.second-1] = 2;
                }
                if(t.second < m-1 && grid[t.first][t.second +1] == 1){
                    q.push({t.first, t.second+1});
                    grid[t.first][t.second+1] = 2;
                }
            }
        }
        int all_fresh = 1, all_empty = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1) return -1;
                if(grid[i][j] != 0) all_empty = 0;
                if(grid[i][j] != 1) all_fresh = 0;
            }
        }
        if(all_fresh == 1 || all_empty == 1)return 0;
        return day-1;
    }
};