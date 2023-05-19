class Solution {
    /*
    if we simply use a new array to record visit, then it encounter tle
    */
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == word[0] && dfs(board, i, j, 0, word)){
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>> &board, int i, int j, int search_c, string word){
        if(i<0||j<0||i>=board.size()||j>=board[0].size())return false;
        
        if(board[i][j] == word[search_c]){
            search_c++;
            if(search_c == word.length()){
                return true;
            }         
            bool check = false;
            char c = board[i][j];
            board[i][j] = '*';
            if(dfs(board, i+1, j, search_c, word))check = true;
            if(dfs(board, i, j+1, search_c, word))check = true;
            if(dfs(board, i-1, j, search_c, word))check = true;
            if(dfs(board, i, j-1, search_c, word))check = true;
            board[i][j] = c;
            return check;
        }
        return false;
    }
};