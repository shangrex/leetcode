class Solution {
public:
    /*
    Approach 1.
    Inspired from: https://leetcode.com/problems/rotate-image/discuss/1175496/JS-Python-Java-C%2B%2B-or-Easy-4-Way-Swap-Solution-w-Explanation
    
    Approach 2.
    First reverse up and down then reflict left and right.
    https://leetcode.com/problems/rotate-image/discuss/18872/A-common-method-to-rotate-the-image
    */
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n/2; i++){
            int len = n-1-i*2;
            for(int j = 0; j < len; j++){
                int tmp = matrix[i][j+i];
                matrix[i][j+i] = matrix[n-j-1-i][i];
                matrix[n-j-1-i][i] = matrix[n-1-i][n-1-j-i];
                matrix[n-1-i][n-1-j-i] = matrix[i+j][n-1-i];
                matrix[i+j][n-1-i] = tmp;
            }
        }
    }
};