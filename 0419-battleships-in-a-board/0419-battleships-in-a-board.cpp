class Solution {
public:
    // void dfs(vector<vector<char>>& board, int i, int j, int rst){
    //     board[i][j] = '.';
    //     int m = board.size(), n = board[0].size();
    //     if(i-1>-1 && board[i-1][j] == 'X') dfs(board, i-1, j, rst);
    //     if(j-1>-1 && board[i][j-1] == 'X') dfs(board, i, j-1, rst);
    //     if(i+1<m && board[i+1][j] == 'X') dfs(board, i+1, j, rst);
    //     if(j+1<n && board[i][j+1] == 'X') dfs(board, i, j+1, rst);
    // }

    void dfs(vector<vector<char>>& board, int i, int j){
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return;
        if(board[i][j] == '.') return;
        board[i][j] = '.';
        dfs(board, i-1, j);
        dfs(board, i, j-1);
        dfs(board, i+1, j);
        dfs(board, i, j+1);
    }
    int countBattleships(vector<vector<char>>& board) {
        int rst = 0;

        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'X'){
                    rst++;
                    dfs(board, i, j);
                }
            }
        }

        return rst;
    }
};