class Solution {
public:
    /*
    approach 1
    a cycle a round,
    go left m-1
    go down n-1
    go right m-1
    go up n-2
    go left m-3
    go down n-3
    go right m-3 ....
    then use count the size of result to stop the loop
    
    code: 
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
    
    
    approach 2
    reduce the boundary
    */
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int dirc[4] = {0, 1, 2, 3};
        vector<int>rst;
        
        int way = 0;
        int i = 0, j = 0, k;
        int top = 0, right = m, left = 0, down = n;
        
        while(top != down && left != right){
            if(dirc[way] == 0){
                // right
                for(k = left; k < right; k++){
                    rst.push_back(matrix[i][k]);
                }
                j = k-1;
                top++;
            }
            else if(dirc[way] == 1){
                // down
                for(k = top; k < down; k++){
                    rst.push_back(matrix[k][j]);
                }
                i = k-1;
                right--;
            }
            else if(dirc[way] == 2){
                // left
                for(k = right-1; k >= left; k--){
                    rst.push_back(matrix[i][k]);
                }
                j = k+1;
                down--;
            }
            else if(dirc[way] == 3){
                // down
                for(k = down-1; k >= top; k--){
                    rst.push_back(matrix[k][j]);
                }
                i = k+1;
                left++;
            }
            way = (way+1)%4;
        }
        return rst;
    }
};