class Solution {
public:
    /*
    Good sample https://leetcode.com/problems/01-matrix/solutions/1369741/c-java-python-bfs-dp-solutions-with-picture-clean-concise-o-1-space/

    Approach 1. BFS 
    queue all 0 
    can optimze the space by replacing visit to mat[r][c] = -1 // marked as visited


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

    Approach 2. DP
    Start from bottom rignt point and go top and left 
    Start from top left point and go right down
    */
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX-n*m));
        // from top left to down right
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    dp[i][j] = 0;
                }
                else {
                    if(i > 0 && j > 0){
                        dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
                    }
                    else if(i > 0){
                        dp[i][j] = min(dp[i-1][j] + 1, dp[i][j]);
                    }
                    else if(j > 0){
                        dp[i][j] = min(dp[i][j-1] + 1, dp[i][j]);
                    }
                }
                if(i == 0 && j == 1) cout << dp[i][j] << endl;
            }
        }

        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                if(mat[i][j] == 0){
                    dp[i][j] = 0;
                }
                else {
                    if(i < n-1 && j < m-1){
                        dp[i][j] = min({dp[i+1][j]+1, dp[i][j+1]+1, dp[i][j]});
                    }
                    else if(i < n-1){
                        dp[i][j] = min(dp[i+1][j] + 1, dp[i][j]);
                    }
                    else if(j < m-1){
                        dp[i][j] = min(dp[i][j+1] + 1, dp[i][j]);
                    }
                }
                if(i == 0 && j == 1) cout << dp[i][j] << endl;

            }
        }

        return dp;
    }
};