class Solution {
public:
    void dfs(vector<vector<pair<int, int>>> &graph, vector<int>&timed, int cost,int n,int k){
        if(timed[k] <= cost){
            return;
        }
        //cout << "visitd " << k << " " << cost << endl;
        timed[k] = cost;
        for(int i = 0; i < graph[k].size(); i++){
            dfs(graph, timed, cost+graph[k][i].second, n, graph[k][i].first);
        }
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        /*
        Approach 1. DFS
        Approach 2. BFS
        Ususally use for unweited graph
        Approach 3. Dijkstra
        Usually use for shortest path in non-negative weights
        Approach 4. Bellmon Fod
        Can find shortest path in negative wieght
        */
        vector<vector<pair<int, int>>> graph(n+1);
        vector<bool>visited(n, true);
        vector<int> timed(n+1, INT_MAX);
        
        for(int i = 0; i < times.size(); i++){
            graph[times[i][0]].push_back({times[i][1], times[i][2]});
            //graph[times[i][1]].push_back({times[i][0], times[i][2]});
        }
        
        // sort(graph.begin(), graph.end(), [](pair<int, int>p1, pair<int, int>p2){
        //     return p1.second < p2.second;
        // });
        
        dfs(graph, timed, 0, n, k);
        int rst = INT_MIN;
        for(int i = 1; i <= n; i++){
            //cout << timed[i] << endl;
            rst = max(rst, timed[i]);
        }
        return rst == INT_MAX ? -1 : rst;
        
    }
};