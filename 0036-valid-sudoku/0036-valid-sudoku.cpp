class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        vector<set<int>>row(n);
        vector<set<int>>col(n);
        vector<set<int>>box(n);
        
        
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == '.')continue;
                
                int pos = board[i][j] - '1';
                if(row[i].count(pos) || col[j].count(pos) || box[(i/3)*3+j/3].count(pos)){
                    return false;
                }
                
                row[i].insert(pos);
                col[j].insert(pos);
                box[(i/3)*3+j/3].insert(pos);
                
            }
        }
        
        return true;
    }
};