class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int>gridRow(n, 0);
        vector<int>gridCol(m, 0);
        int total = 0;
        int minus = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    total+=1; 
                    gridRow[i] += 1;
                    gridCol[j] += 1;
                }
            }
        }
        
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && gridRow[i] == 1 && gridCol[j] == 1){
                    // isolation
                    count += 1;
                }
            }
        }
     
        cout << total  << endl;
       
        return total - count;
    }
};