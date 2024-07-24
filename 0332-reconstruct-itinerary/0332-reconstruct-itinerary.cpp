class Solution {
public:
    void dfs(string cur, unordered_map<string, vector<string>>& graph, vector<string>&rst){

        while(!graph[cur].empty()){
            string tmp = graph[cur].back();
            graph[cur].pop_back();
            dfs(tmp, graph, rst);
        }
        rst.push_back(cur);
        
        return;
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        /*
        Approach 1. DFS 
        Hint: only one stuck points, so just use post-ordered dfs and reverse in the end
        route-based triversing
        */
        vector<string>rst;
        unordered_map<string, vector<string>> graph;
        for(auto &ticket : tickets){
            graph[ticket[0]].push_back(ticket[1]);
        }
        
        for(auto &g : graph){
            sort(g.second.begin(), g.second.end(), greater<string>());
        }
        
        dfs("JFK", graph, rst);
        reverse(rst.begin(), rst.end());
        return rst;
    }
};