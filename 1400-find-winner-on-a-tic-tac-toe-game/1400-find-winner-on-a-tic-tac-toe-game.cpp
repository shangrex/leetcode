class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int player = 0;
        vector<vector<char>> square(3, vector<char>(3));
        for(auto &move : moves){
            if(player %2 == 0)
                square[move[0]][move[1]] = 'X';
            else 
                square[move[0]][move[1]] = 'O';
            player++;
        }

        int tmp = 0;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(square[i][j] == 'X') tmp++;
            }
            if(tmp==3)return "A";
            tmp = 0;
            for(int j = 0; j < 3; j++){
                if(square[j][i] == 'X') tmp++;
            }
            if(tmp==3)return "A";
            tmp = 0;
        }
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(square[i][j] == 'O') tmp++;
            }
            if(tmp==3)return "B";
            tmp = 0;
            for(int j = 0; j < 3; j++){
                if(square[j][i] == 'O') tmp++;
            }
            if(tmp==3)return "B";
            tmp = 0;
        }

        if(square[0][0] == 'X' && square[1][1] == 'X' && square[2][2] == 'X') return "A";
        if(square[0][2] == 'X' && square[1][1] == 'X' && square[2][0] == 'X') return "A";
        if(square[0][2] == 'O' && square[1][1] == 'O' && square[2][0] == 'O') return "B";
        if(square[0][0] == 'O' && square[1][1] == 'O' && square[2][2] == 'O') return "B";
        if(moves.size() == 9) return "Draw";
        return "Pending";
    }
};