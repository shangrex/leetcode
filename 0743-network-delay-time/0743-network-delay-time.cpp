class Solution {
public:
    /*
    Approach 1. DFS
    Approach 2. BFS. The same node would push to queue multiple time so slower to Approach 3
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
    
    Approach 3. Dijkstra's Algorithm
        int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n+2);

        for(auto& edges : times){
            int u = edges[0];
            int v = edges[1];
            int w = edges[2];
            graph[u].push_back({w, v});
        }
        vector<int> weights(n+2, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, k});
        weights[k] = 0;
        while(!pq.empty()){
            int m = pq.size();
            for(int i = 0; i < m; i++){
                auto node = pq.top();
                pq.pop();
                for (auto& t : graph[node.second]){
                    int nextNode = t.second;
                    int gap = t.first;
                   if(weights[node.second] - weights[nextNode] + gap < 0){
                        int val = weights[node.second]+gap;
                        pq.push({val, nextNode});
                        weights[nextNode] = val;
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
    */
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n+2);
        priority_queue<pair<int, int>, vector<pair<int, int>>, 
        greater<pair<int, int>> > pq;

        for(int i = 0; i < times.size(); i++){
            graph[times[i][0]].push_back({times[i][1], times[i][2]});
        }

        vector<int> delayMap(n+2, INT_MAX);
        pq.push({0, k});
        delayMap[k] = 0;
        
        while(!pq.empty()){
            int m = pq.size();
            for(int i = 0; i < m; i++){
                pair<int, int> topNode = pq.top();
                int curNode = topNode.second;
                int curDelay = topNode.first;
                pq.pop();

                for(auto &i : graph[curNode]){
                    int nxtNode = i.first;
                    int delay = i.second;
                    if(delay  < delayMap[nxtNode] - delayMap[curNode]){
                        // smaller 
                        delayMap[nxtNode] = delay+delayMap[curNode];
                        pq.push({delayMap[nxtNode], nxtNode});
                    }
                }
            
            }
        }

        int ret = INT_MIN;
        for(int i = 1; i <= n;i++){
            if(delayMap[i] == INT_MAX){
                return -1;
            }
            ret = max(ret, delayMap[i]);
        }

        return ret;
    }
};