class Solution {
public:
    /*
    BFS + prioirty_queue
    */
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        int m = heightMap[0].size();

        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++){
            pq.push({heightMap[i][0], i, 0 });
            visited[i][0] = true;
            pq.push({heightMap[i][m-1], i, m-1});
            visited[i][m-1] = true;
        }

        for(int i = 1; i < m-1; i++){
            pq.push({heightMap[0][i], 0, i});
            visited[0][i] = true;
            pq.push({heightMap[n-1][i], n-1, i});
            visited[n-1][i] = true;
        }

        vector<vector<int>> dirc = {
            {0, -1},
            {0, 1},
            {1, 0},
            {-1, 0}
        };

        int totalRain = 0;
        while(!pq.empty()){
            auto [height, x, y] = pq.top();
            pq.pop();
            // cout << x << y  << endl;
            for(int i = 0; i < 4; i++){
                int nx = x+dirc[i][0];
                int ny = y+dirc[i][1];
                if(nx >= n || nx < 0
                    || ny >= m || ny < 0
                    || visited[nx][ny]) continue;
                if(heightMap[nx][ny] < heightMap[x][y]){
                    totalRain += (heightMap[x][y] - heightMap[nx][ny]);
                    // cout << nx << ny << totalRain << endl;
                }
                heightMap[nx][ny] = max(heightMap[x][y], heightMap[nx][ny]);
                visited[nx][ny] = true;
                pq.push({heightMap[nx][ny], nx, ny});
            }
        }


        return totalRain;
    }
};