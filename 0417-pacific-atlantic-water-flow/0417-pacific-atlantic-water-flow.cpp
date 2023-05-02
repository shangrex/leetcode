class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        vector<vector<int>> res;
        if(heights.size() == 0)return res;
        
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int> >map(n, vector<int>(heights[0].size(), 0));
        // construce the map
        // the place that water can flow into pacific ocean is 1
        // the place that water can flow into atlantic ocean is 2
        // the place that water can both is 3
        for(int i = 0; i < n; i++){
            // check the left side of the island
            dfs(i, 0, 1, map, res, heights);
            // check the right side of the island
            dfs(i, m-1, 2, map, res, heights);
        }
        for(int i = 0; i < m; i++){
            // check the up side of the island
            dfs(0, i, 1, map, res, heights);
            // check the down side of the island
            dfs(n-1, i, 2, map, res, heights);
        }
        return res;
    }
    
    void dfs(int row, int col, int ocean, vector<vector<int>> &map, vector<vector<int>> &res, vector<vector<int>>& heights){
        int n = heights.size();
        int m = heights[0].size();
        
        // cout << row << " " << col << endl;
        // for(int i = 0;i < n; i++){
        //     for(int j = 0; j < m; j++){
        //         cout << map[i][j] << " ";
        //     }
        //     cout << endl;
        // }        
        // cout << endl;
        
        
        if(map[row][col] == 1 && ocean == 2){
            res.push_back({row, col});
            map[row][col] = 3;
        }
        else if(map[row][col] == 2 && ocean == 1){
            res.push_back({row, col});
            map[row][col] = 3;
        }
        
      
        if(map[row][col] != 3)map[row][col] = ocean;
        //up
        if(row-1>=0){
            if(heights[row-1][col] >= heights[row][col] && map[row-1][col] != map[row][col]){
                dfs(row-1, col, ocean, map, res, heights);   
            }
        }
        //down
        if(row+1<n){
            if(heights[row+1][col] >= heights[row][col]  && map[row+1][col] != map[row][col]){
                dfs(row+1, col, ocean, map, res, heights);   
            }
        }
        //left
        if(col-1>=0){
            if(heights[row][col-1] >= heights[row][col]  && map[row][col-1] != map[row][col]){
                dfs(row, col-1, ocean, map, res, heights);   
            }
        }
        //right
        if(col+1<m){
            if(heights[row][col+1] >= heights[row][col]  && map[row][col+1] != map[row][col]){
                dfs(row, col+1, ocean, map, res, heights);   
            }
        }
    }
};