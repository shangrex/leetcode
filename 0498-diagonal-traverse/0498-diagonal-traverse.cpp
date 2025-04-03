class Solution {
public:
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