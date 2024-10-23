class Solution {
public:
    /*
    Approach 1. BFS + binary search
        To search whether reach the end -> BFS
        To search the minimun water level -> binary search
    Appraoch 2. priority_queue + BFS
    */
    
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> > pq;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        int rst = grid[0][0];
        pq.push({rst, 0, 0});
        visited[0][0] = 1;        
        
        while(!pq.empty()){
            
            vector<int>p = pq.top();
            int row = p[1];
            int col = p[2];
            visited[row][col] = 1;
            //cout << row << " " << col << endl;
            rst = max(rst, p[0]);
            if(row == n-1 && col == n-1){
                return rst;
            }
            pq.pop();
            if(row > 0 && visited[row-1][col] == 0){
                pq.push({grid[row-1][col], row-1, col});
            }
            if(row < n-1 && visited[row+1][col] == 0){
                pq.push({grid[row+1][col], row+1, col});
            }
            if(col > 0 && visited[row][col-1] == 0 ){
                pq.push({grid[row][col-1], row, col-1});
            }
            if(col < n-1 && visited[row][col+1] == 0){
                pq.push({grid[row][col+1], row, col+1});
            }
                
        }
        return -1;
    }
};