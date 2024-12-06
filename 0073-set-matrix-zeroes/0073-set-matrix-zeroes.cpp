class Solution {
public:
    /*
    approach 1: bruce force iterate the matrix and set all col and row to zero
    apporach 2: use dynamic programming, use two array to record the which row and col should be zero
    approach 3: optimize method, use two boolean value to represent  first row or col should all be zero or not.
    */
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int>row(n, 0);
        vector<int>col(m, 0);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(row[i] == 1){
                for(int j = 0; j < m;j++){
                    matrix[i][j] = 0;
                }
            }
        }

        for(int i = 0; i < m; i++){
            if(col[i] == 1){
                for(int j = 0; j < n; j++){
                    matrix[j][i] = 0;
                }
            }
        }
    }
};