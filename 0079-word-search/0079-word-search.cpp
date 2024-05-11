class Solution {
public:
    
    bool backtrack(int row, int col, int s_index, string &word, vector<vector<char>>& board, vector<vector<bool>>&visited){
        
        if(s_index == word.length())return true;

        if(row < 0 || row >= board.size())return false;
        if(col < 0 || col >= board[0].size())return false;
        bool a ,b, c, d;
        a = b = c = d = false;
        visited[row][col] = true;
        if(row+1<board.size() && board[row+1][col] == word[s_index] && !visited[row+1][col]){
            a = backtrack(row+1, col, s_index+1, word, board, visited);
        }
        if(col+1 < board[0].size() && board[row][col+1] == word[s_index] && !visited[row][col+1]){
            c = backtrack(row, col+1, s_index+1, word, board, visited);
        }
        if(row>0 && board[row-1][col] == word[s_index] && !visited[row-1][col]){
            b = backtrack(row-1, col, s_index+1, word, board, visited);
        }
        if(col>0 && board[row][col-1] == word[s_index] && !visited[row][col-1]){
            d = backtrack(row, col-1, s_index+1, word, board, visited);
        }
        visited[row][col] = false;
       
        return a || b || c || d;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>>visited(board.size(), vector<bool>(board[0].size(), false));
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == word[0]){
                    bool a = backtrack(i, j, 1, word, board, visited);
                    if(a)return true;
                }
            }
        }
        return false;
    }
};