class Solution {
public:
    /*
    Hint: only need to find not surrounded regions
    */
    int m, n;
    void dfs(vector<vector<char>> &board, int i, int j){
        if(i < 0 || j < 0 || i >= m || j >= n)return;
        cout << i << " " << j << endl;
        if(board[i][j] == 'O'){
            board[i][j] = '#';
            dfs(board, i-1, j);
            dfs(board, i+1, j);
            dfs(board, i, j-1);
            dfs(board, i, j+1);
        }
    }
    void solve(vector<vector<char>>& board) {
        this->m = board.size();
        this->n = board[0].size();
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 || i == m-1 || j == 0 || j == n-1){
                    if(board[i][j] == 'O'){
                        // change to other char '#'
                        dfs(board, i, j);
                    }
                }
            }
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
                else if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
    
    
    
};