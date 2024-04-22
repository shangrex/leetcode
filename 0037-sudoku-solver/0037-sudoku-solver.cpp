class Solution {
    /*
    nice solution: https://leetcode.com/problems/sudoku-solver/discuss/15853/Simple-and-Clean-Solution-C%2B%2B
    */
public:
    bool check(vector<vector<char>> &board, int row, int col, char c){
        // check row
        for(int i = 0; i < 9; i++) if(board[i][col] == c)return false;
        // check col
        for(int i = 0; i < 9; i++) if(board[row][i] == c)return false;
        // check boxes
        int box_row = (row/3)*3, box_col = (col/3)*3;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(board[box_row+i][box_col+j] == c){
                    return false;
                }
            }
        }
        
        return true;
    }
    bool solve(vector<vector<char>> &board, int row, int col){
        if(row == 9)return true;
        if(col >= 9){
            return solve(board, row+1, 0);
        }
        
        if(board[row][col] != '.') return solve(board, row, col+1);
        
        for(int i = 0; i < 9; i++){
            if(check(board, row, col, i+'1')){
                board[row][col] = i+'1';
                if(solve(board, row, col+1))return true;
                board[row][col] = '.';
            }
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        solve(board, 0, 0);
    }
};