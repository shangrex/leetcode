class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        // find target row
        int i = 0, j = row;
        while(i < j){
            // cout << i << j << endl;
            int m = (i+j)/2;
            if(matrix[m][0] == target){
                i = m;
                return true;
                break;
            }
            else if(matrix[m][0] > target){
                j = m;
            }
            else i=m+1;
        }
        
        int target_i = i-1;
        if(target_i < 0)target_i = 0;
        i = 0, j = col;
        while(i < j){
            int m = (i+j)/2;
            
            // cout << i << j << endl;
            
            if(matrix[target_i][m] == target){
                i = m;
                return true;
                break;
            }
            else if(matrix[target_i][m] > target){
                j = m;
            }
            else i = m+1;
        }
        int target_j = i-1;
        // cout << target_i << " " << target_j << endl;
        return false;
        
    }
};