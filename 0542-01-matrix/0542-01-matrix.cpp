class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // push all 1 in queue
        // every ajacent in 
        int m = mat.size();
        int n = mat[0].size();

        queue<pair<int ,int>>q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> rst(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }
        int level = 0;
        while(!q.empty()){
            int level_size = q.size();
            for(int i = 0; i < level_size; i++){
                pair<int, int>p = q.front();
                q.pop();
                int r = p.first;
                int c = p.second;
                cout << r <<" " << c << " " << level << endl;

                rst[r][c] = level;
                if(r+1 < m && !visited[r+1][c]){
                    q.push({r+1, c});
                    visited[r+1][c] = true;
                }
                if(c+1 < n && !visited[r][c+1]){
                    q.push({r, c+1});
                    visited[r][c+1] = true;
                }
                if(r > 0 && !visited[r-1][c]){
                    q.push({r-1, c});
                    visited[r-1][c] = true;
                }
                if(c > 0 && !visited[r][c-1]){
                    q.push({r, c-1});
                    visited[r][c-1] = true;
                }
            }
            level++;
        }
        return rst;
    }
};