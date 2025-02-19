class Solution {
public:
    bool inboard(vector<vector<char>> &board, int x, int y){
        return ((x > -1) && (y > -1) && x < board.size() && y < board[0].size());
    }

    void dfs(vector<vector<char>>&board, int x, int y){
        if(!inboard(board, x, y)) return;
        if(board[x][y] == 'B') return;
        if(board[x][y] != 'E') return;

        int count = 0;
        if(inboard(board,x-1,y-1) && board[x-1][y-1] == 'M') count++;
        if(inboard(board,x-1,y  ) && board[x-1][y  ] == 'M') count++;
        if(inboard(board,x-1,y+1) && board[x-1][y+1] == 'M') count++;
        if(inboard(board,x  ,y-1) && board[x  ][y-1] == 'M') count++;
        if(inboard(board,x  ,y+1) && board[x  ][y+1] == 'M') count++;
        if(inboard(board,x+1,y-1) && board[x+1][y-1] == 'M') count++;
        if(inboard(board,x+1,y  ) && board[x+1][y  ] == 'M') count++;
        if(inboard(board,x+1,y+1) && board[x+1][y+1] == 'M') count++;  

        if(count > 0){
            board[x][y] = '0'+count;
        }
        else {
            board[x][y] = 'B';
            dfs(board,x-1,y-1);
            dfs(board,x-1,y  );
            dfs(board,x-1,y+1);
            dfs(board,x  ,y-1);
            dfs(board,x  ,y+1);
            dfs(board,x+1,y-1);
            dfs(board,x+1,y  );
            dfs(board,x+1,y+1);
        }
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int x = click[0], y = click[1];
        if(board[x][y] == 'M'){
            board[x][y] = 'X';
            return board;
        }
        dfs(board, x, y);
        return board;
    }
};