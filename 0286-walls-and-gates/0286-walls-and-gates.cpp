class Solution {
public:
    bool isValid(int x, int y, int n, int m, vector<vector<int>>&rooms){
        if(x >= n || y >= m || x < 0 || y < 0) return false;
        if(rooms[x][y] != INT_MAX) return false;
        return true;
    }
    void wallsAndGates(vector<vector<int>>& rooms) {
        int n = rooms.size();
        int m = rooms[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> visited (n+1, vector<int>(m+1, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(rooms[i][j] == 0){
                    q.push({i, j});
                    visited[i][j] = 1;
                }
            }
        }

        vector<vector<int>> dirc = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
        };
        int level = 0;
        while(!q.empty()){

            int k = q.size();
            for(int j = 0;j < k; j++){
                pair<int, int> p = q.front();
                q.pop();
                int x = p.first;
                int y = p.second;
                rooms[x][y] = level;
                for(int i = 0; i < 4; i++){
                    if(isValid(x+dirc[i][0], y+dirc[i][1], n, m, rooms) 
                    && visited[x+dirc[i][0]][y+dirc[i][1]] == 0){
                        q.push({x+dirc[i][0], y+dirc[i][1]});
                        visited[x+dirc[i][0]][y+dirc[i][1]] = 1;
                    }
                }
            }
            level++;
        }
    }
};