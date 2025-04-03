class Solution {
public:
    /*
    2, 4 are on the same diagonal, and they share the index sum of 1. 
    (2 is matrix[0][1] and 4 is in matrix[1][0]). 3,5,7 are on the same diagonal, and they share the sum of 2. (3 is matrix[0][2], 5 is matrix[1][1], and 7 is matrix [2][0]).


    */
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n= mat[0].size();

        vector<vector<int>> tmp(m+n, vector<int>());

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                tmp[i+j].push_back(mat[i][j]);
            }
        }

        vector<int> ret;
        for(int i = 0; i < m+n; i++){
            if(i % 2 == 0){
                reverse(tmp[i].begin(), tmp[i].end());
            }

            for(auto j : tmp[i]){
                ret.push_back(j);
            }
        }
        return ret;
    }
};