class Solution {
public:
    /*
    Approach 1. DFS
    Approach 2. BFS
    Approach 3. Dijkesy
    */
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n+2);

        for(auto& edges : times){
            int u = edges[0];
            int v = edges[1];
            int w = edges[2];
            graph[u].push_back({v, w});
        }
        vector<int> weights(n+2, INT_MAX);
        queue<int>q;
        q.push(k);
        weights[k] = 0;
        while(!q.empty()){
            int m = q.size();
            for(int i = 0; i < m; i++){
                int node = q.front();
                q.pop();
                for (auto& t : graph[node]){
                    int nextNode = t.first;
                    int gap = t.second;
                   if(weights[node] - weights[nextNode] + gap < 0){
                        q.push(nextNode);
                        weights[nextNode] = weights[node]+gap;
                    }
                }
            }
        }
        int ret = INT_MIN;
        for(int i = 1; i <= n; i++){
            ret = max(ret, weights[i]);
        }
        return ret == INT_MAX ? -1 : ret;
    }
};