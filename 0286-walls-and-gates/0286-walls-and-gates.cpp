class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<pair<int, int>>q;
        int n  = rooms.size();
        int m = rooms[0].size();
        
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(rooms[i][j] == 0){
                    q.push({i, j});
                }
            }
        }
        
        int step = 0;
        while(!q.empty()){
            int level = q.size();
            step++;
            
            //cout << level << endl;
            //cout << step << endl;
     
            for(int i = 0; i < level; i++){
               pair<int, int>p = q.front();
                q.pop();
                int w = p.first;
                int h = p.second;
                if(w > 0 && rooms[w-1][h] == INT_MAX){
                    q.push({w-1, h});
                    rooms[w-1][h] = min(step, rooms[w-1][h]);
                }
                if(w+1 < n && rooms[w+1][h] == INT_MAX){
                    rooms[w+1][h] = min(step, rooms[w+1][h]);
                    q.push({w+1, h});
                }
                if(h > 0 && rooms[w][h-1] == INT_MAX){
                    q.push({w, h-1});
                    rooms[w][h-1] = min(step, rooms[w][h-1]);
                }
                if(h+1 < m && rooms[w][h+1] == INT_MAX){
                    rooms[w][h+1] = min(step, rooms[w][h+1]);
                    q.push({w, h+1});
                }
            }            
        }
        
    }
};