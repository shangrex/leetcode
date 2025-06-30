class Solution {
public:
    int recursive(int i, int j,vector<vector<char>>&matrix, vector<vector<int>> &memo){
        if(i >= matrix.size() || j >= matrix[0].size() || i < 0 || j < 0) return 0;
        if(matrix[i][j] == '0') return memo[i][j];
        if(memo[i][j] > 0) return memo[i][j];
        return memo[i][j] = min({recursive(i-1, j, matrix, memo),
                            recursive(i, j-1, matrix, memo), 
                            recursive(i-1, j-1, matrix, memo)})+1;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ret = 0;
        vector<vector<int>> memo(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int t= recursive(i, j, matrix, memo);
                ret = max(t, ret);
            }
        }
        
        return ret*ret;
    }
};