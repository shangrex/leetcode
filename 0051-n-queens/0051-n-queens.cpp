class Solution {
public:
    
    bool isvalid(vector<string>q_map, int col, int row, int n){
        // check col
        for(int i = 0; i < n; i++){
            if(q_map[col][i] == 'Q')return false;
        }
        // check 135
        for(int i = col-1, j = row-1; i>=0 && j>=0; i--, j--){
            if(q_map[i][j] == 'Q')return false;
        }
        // check 45
        for(int i = col+1, j = row-1; i < n && j >= 0; i++, j--){
            if(q_map[i][j] == 'Q')return false;
        }
        return true;
    }
    
    void backtrack(int n, vector<vector<string>> &rst, int col, int row, vector<string>q_map){
        if(row == n){
            rst.push_back(q_map);
            return;
        }
        
        for(int i = 0; i < n; i++){
            if(isvalid(q_map, i, row, n)){
                q_map[i][row] = 'Q';
                backtrack(n, rst, col, row+1, q_map);
                q_map[i][row] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> rst;
        int size = n;
        vector<string> q_map(n, string(n, '.'));
        
        backtrack(n, rst, 0, 0, q_map);
  
        return rst;
    }
};