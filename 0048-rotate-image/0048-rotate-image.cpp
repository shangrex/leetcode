class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int time = n/2+n%2;
        for(int i = 0; i < time; i++){
            // a round
            for(int j = 0; j < n-1; j++){
                int tmp = matrix[i+0][i+0+j];
                matrix[i+0][i+0+j] = matrix[n+i-j-1][i+0];
                matrix[n+i-j-1][i+0] = matrix[n+i-1][n+i-j-1];
                matrix[n+i-1][n+i-j-1] = matrix[0+i+j][n+i-1];
                matrix[0+i+j][n+i-1] = tmp;
            }
            
            n = n-2;
        }
    }
};