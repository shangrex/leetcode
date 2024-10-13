class Solution {
public:
    int n, m;
    
    void dfs(vector<vector<int>>&heights, vector<vector<int>> &record, int x, int y, int fill){
        // cout << x <<" " << y << fill << endl;
        if(x < 0 || x >= m || y < 0 || y >= n){
            return;
        }
        if(record[y][x] == 1 && fill == 2) {
            record[y][x] = 3;
        }
        else if(record[y][x] != 3)record[y][x] = fill;
        if(x < m-1 && heights[y][x] <= heights[y][x+1] && record[y][x+1] != fill  && record[y][x+1] != 3){
            dfs(heights, record, x+1, y, fill);
        }
        // cout << n<< endl;
        // cout << x << " " << y+1 << endl;
        if(y < n-1 && heights[y][x] <= heights[y+1][x] && record[y+1][x] != fill && record[y+1][x] != 3) {
            dfs(heights, record, x, y+1, fill);
        }
        if(x > 0 && heights[y][x] <= heights[y][x-1] && record[y][x-1] != fill && record[y][x-1] != 3){
            dfs(heights, record, x-1, y, fill);
        }
        if(y > 0 && heights[y][x] <= heights[y-1][x] && record[y-1][x] != fill && record[y-1][x] != 3){
            dfs(heights, record, x, y-1, fill);
        }
        
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        this->n = heights.size();
        this->m = heights[0].size();
        
        // 1 is pacific, 2 is Atlantic, 3 is both
        vector<vector<int>> record(n, vector<int>(m, 0));
        
        for(int i = 0; i < m; i++){
            dfs(heights, record, i, 0, 1);
        }
        
        for(int i = 0; i < n; i++){
            dfs(heights, record, 0, i, 1);
        }
       for(int i = 0; i < m; i++){
            dfs(heights, record, i, n-1, 2);
        }
        for(int i = 0; i < n; i++){
            dfs(heights, record, m-1, i, 2);
        }
        vector<vector<int>> rst;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << record[i][j];
                if(record[i][j] == 3){
                    rst.push_back({i, j});
                }
                cout << " ";
            }
            cout << endl;
        }
        return rst;
    }
};