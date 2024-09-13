class Solution {
public:
    /*
    
    Approach 1. Observe a cycle a round,
    if we start on i = 0, j = -1
    go right m
    go down n-1
    go right m-1
    go up n-2
    go left m-2
    go down n-3
    go right m-4 ....
    
    right and left is lower and lower by one
    so as top and bottom
    
    Approach 2. set up the boundary and then triverse
    */
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>rst;
        int w = 0, h = -1;
        int dirct = 0;
        int n = matrix.size()-1;
        int m = matrix[0].size();
        
        while(n >= 0 && m >= 0){
            cout << w << " " << h << endl;
            cout << "f" << n << " " << m << endl;
            if(dirct == 0){
                // right
                for(int i = 1; i <= m; i++){
                    h++;
                    rst.push_back(matrix[w][h]);
                }
                m--;
            }
            if(dirct == 1){
                // down
                for(int j = 1; j <= n; j++){
                    w++;
                    //cout << w << " " << endl;
                    rst.push_back(matrix[w][h]);
                }
                n--;
            }
            if(dirct == 2){
                for(int i = 1; i <= m; i++){
                    h--;
                    rst.push_back(matrix[w][h]);
                }
                m--;
            }
            if(dirct == 3){
                for(int j = 1; j <= n; j++){
                    w--;
                    rst.push_back(matrix[w][h]);
                }
                n--;
            }
            dirct = (dirct + 1) % 4;
        }
        
        return rst;
    }
};