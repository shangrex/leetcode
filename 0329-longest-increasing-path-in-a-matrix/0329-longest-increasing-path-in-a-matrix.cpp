class Solution {
public:
    /*
    Hint: dfs + memo
    */
    vector<vector<int>> dirc = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> memo(n, vector<int>(m, -1));
        int rst = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0;j < m; j++){
                rst = max(rst, dfs(matrix, memo, i, j));
            }
        }

        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < m; j++){
        //         cout << memo[i][j] << " ";
        //     }
        //     cout << endl;
        // }


        return rst+1;
    }

    int dfs(vector<vector<int>>& matrix, vector<vector<int>> &memo, int i, int j){
        if(memo[i][j] != -1) return memo[i][j];
        int n = matrix.size();
        int m = matrix[0].size();
        
        for(int k = 0; k < 4; k++){
            if(i+dirc[k][0] > -1 && i+dirc[k][0] < n && j+dirc[k][1] > -1 && j+dirc[k][1] < m && matrix[i+dirc[k][0]][j+dirc[k][1]] > matrix[i][j]){
                memo[i][j] = max(memo[i][j],  dfs(matrix, memo, i+dirc[k][0], j+dirc[k][1]));
            }
        }

        return ++memo[i][j];
    }
};