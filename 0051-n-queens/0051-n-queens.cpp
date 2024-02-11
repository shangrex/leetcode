class Solution {
public:
    bool isvalid(int n, vector<string>board, int row, int col){
        // 
        for(int i = 1; i <= row; i++){
            if(board[row-i][col] == 'Q')return false;
        }
        for(int i = 1; i <=row && col+i<n; i++){
            if(board[row-i][col+i] == 'Q')return false;
        }
        for(int i = 1; i <= row && i <= col; i++){
            if(board[row-i][col-i] == 'Q')return false;
        }
        return true;
    }
    void backtrack(int n, vector<vector<string>> &rst, vector<string>&board, int row, int col){
        if(n == row){
            rst.push_back(board);
            return;
        }
        
        
        for(int i = 0; i < n; i++){
            if(isvalid(n, board, row, i)){
                board[row][i] = 'Q';
                backtrack(n, rst, board, row+1, col);
                board[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string> > rst;
        vector<string>board(n, string(n, '.'));
        
        backtrack(n, rst, board, 0, 0);
        
        return rst;
    }
    
    
};