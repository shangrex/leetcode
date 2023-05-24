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
        bool first_element_row_zero = false;
        bool first_element_col_zero = false;
        // check row col first element if zero
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    if(i == 0)first_element_row_zero = true;
                    if(j == 0)first_element_col_zero = true;
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        
        for(int i = 1; i < n; i++){
            if(matrix[i][0] == 0){
                for(int j = 0; j < m; j++){
                    matrix[i][j] = 0;
                }
            }
        }

        for(int j = 1; j < m; j++){
            if(matrix[0][j] == 0){
                for(int i = 0; i < n; i++){
                    matrix[i][j] = 0;
                }
            }
        }
        if(first_element_col_zero){
            for(int i = 0; i < n; i++){
                matrix[i][0] = 0;
            }
        }
        if(first_element_row_zero){
            for(int j = 0; j < m; j++){
                matrix[0][j] = 0;
            }
        }
    }
};