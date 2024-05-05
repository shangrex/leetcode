class Solution {
public:
    /*
    Approach 1. BFS
    Best choice for unweighted graph, (still okay for weighted)
    
    Approach 2. Bellmond Fold 
    Can find negative and positive shortest path
    
    Approach 3. Dijsktra 
    Can only find positive shortest path
    */
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>visited(n, 0);
        // left one is destination, right one is weighted
        vector<vector<pair<int, int>>> graph(n);
        // store minimal  cost from src
        vector<int>rst(n, INT_MAX);
        
        // 1. construct the graph
        for(auto flight : flights){
            graph[flight[0]].push_back({flight[1], flight[2]});
        }
        
        // 2. Initialize queue
        // queue should be pair, consider the same level would interactive with each others, and 
        // the calculation should be wrong
        // ex 4
        // [[0,1,1],[0,2,5],[1,2,1],[2,3,1]]
        // 0
        // 3
        // 1
        queue<pair<int, int>>q;
        q.push({src, 0});
        visited[src] = 1;
        rst[src] = 0;
        
        // 3. BFS
        int cnt_step = 0;
        bool approach = false;
        while(cnt_step <= k && !q.empty()){
            int sz = q.size();
            for(int i = 0;  i < sz; i++){
                pair<int,int> cur = q.front();
                // cout << cur << endl;
                q.pop();

                for(auto near : graph[cur.first]){
                    if(near.second + cur.second > rst[near.first])continue;
                    q.push({near.first, near.second + cur.second});
                    // cout << near.second + rst[cur] << endl;
                    rst[near.first] = near.second + cur.second;
                }
            }
            cnt_step ++;
        }
        
        if(rst[dst] != INT_MAX) return rst[dst];
        else return -1;
    }
};