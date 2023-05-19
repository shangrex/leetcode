class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int dirc[4][3] = {{0, 1, m-1}, {1, 0, n-1}, {0, -1, m-1}, {-1, 0, n-2}};
        vector<int>rst;
        
        int way = 0;
        int i = 0, j = -1;
        int cnt = 0;
        while(cnt < m*n){
            if(way == 0){
                j += 1;
                cnt ++;
                rst.push_back(matrix[i][j]);
            }
            int step = dirc[way][2];
            while(step > 0){
                cnt++;
                step -= 1;
                i = i+dirc[way][0], j = j+dirc[way][1];
                rst.push_back(matrix[i][j]);
            }
            dirc[way][2] -= 2;
            way = (way+1)%4;
    
        }
        return rst;
    }
};