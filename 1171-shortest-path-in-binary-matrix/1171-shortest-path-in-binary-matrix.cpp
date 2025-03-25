class Solution {
public:

    /*
    Approach 1. BFS in-place 
    use grid to store the visited & path

    Approach 2. use # of bfs for path and visited to not change the value of grid
    */
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, -1));

        if(grid[0][0] == 0){
            q.push({0, 0});
            visited[0][0] = 1;
        }

        vector<vector<int>> dirt = {{1, 1}, {1, 0}, {0, 1}, {1, -1},
                                {-1, 1}, {-1, 0}, {0, -1}, {-1, -1}};
        
        int path = 0;
        while(!q.empty()){
            path++;
            int level = q.size();
            for(int i = 0; i < level; i++){
                pair<int, int> t = q.front();
                q.pop();
                int row = t.first;
                int col = t.second;
                cout << row << " " << col << " " << path << endl;
                cout << n-1 << m-1<<endl;
                if(t.first == n-1 && t.second == m-1) return path;

                for(int j = 0; j < 8; j++){
                    int nx = row+dirt[j][0];
                    int ny = col+dirt[j][1];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && 
                        visited[nx][ny] == -1 && grid[nx][ny] == 0){
                        q.push({nx, ny});
                        visited[nx][ny] = 1;

                        // grid[nx][ny] = grid[row][col]+1;
                    }
                }
            }
        }

        return -1;
    }
};