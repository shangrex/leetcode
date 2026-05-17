class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> pq;
        // push 
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 2){
                    pq.push({i, j});
                }
            }
        }
        vector<vector<int>> dirc = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int minutes = 0;
        bool flag = false;
        while(!pq.empty()){
            int level = pq.size();
            if(!flag){minutes--; flag = true;}
            // if(minutes == 0) minutes --;
            minutes++;
            for(int j = 0; j < level; j++){
                pair<int, int> pr;
                pr = pq.front();
                pq.pop();
                int x = pr.first, y = pr.second;
                cout << x << y << endl;
                for(int i = 0; i < 4; i++){
                    if(x+dirc[i][0] > -1 && x+dirc[i][0] < grid.size() &&
                        y+dirc[i][1] > -1 && y+dirc[i][1] < grid[0].size() &&
                        grid[x+dirc[i][0]][y+dirc[i][1]] == 1){
                        grid[x+dirc[i][0]][y+dirc[i][1]] = 2;
                        pq.push({x+dirc[i][0], y+dirc[i][1]});
                    }
                }
            }
        }

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return minutes;
    }
};