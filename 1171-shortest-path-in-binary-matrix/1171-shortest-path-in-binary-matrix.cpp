class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, -1));

        q.push({0, 0});
        visited[0][0] = 1;
        if(grid[0][0] == 1) return -1; 
        grid[0][0] = 1;

        vector<vector<int>> dirt = {{1, 1}, {1, 0}, {0, 1}, {1, -1},
                                {-1, 1}, {-1, 0}, {0, -1}, {-1, -1}};
        while(!q.empty()){
            for(int i = 0; i < q.size(); i++){
                pair<int, int> t = q.front();
                q.pop();
                int row = t.first;
                int col = t.second;
                visited[row][col] = 1;
                if(t.first == n-1 && t.second == m-1) return grid[n-1][m-1];

                for(int j = 0; j < 8; j++){
                    int nx = row+dirt[j][0];
                    int ny = col+dirt[j][1];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 0){
                        q.push({nx, ny});
                        grid[nx][ny] = grid[row][col]+1;
                    }
                }
            }
        }

        return -1;
    }
};