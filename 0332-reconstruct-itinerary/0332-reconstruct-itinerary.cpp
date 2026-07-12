class Solution {
public:

    void dfs(string src, unordered_map<string, vector<string>> &graph, vector<string> &ret){
        string tgt;
        while(!graph[src].empty()){
            tgt = graph[src].back();
            graph[src].pop_back();
            dfs(tgt, graph, ret);
        }
        ret.push_back(src);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> graph;

        for(int i = 0; i < tickets.size(); i++){
            graph[tickets[i][0]].push_back(tickets[i][1]);
        }

        for(auto & g : graph){
            sort(g.second.begin(), g.second.end(), greater<string>());
        }

        vector<string> ret;
        dfs("JFK", graph, ret);
        reverse(ret.begin(), ret.end());
        return ret;
    }
};