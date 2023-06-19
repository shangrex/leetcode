class Solution {
public:
    void dfs(unordered_map<string, double>&graph, unordered_map<string, vector<string>>&mp, string &start, string &end, double &division, map<string, bool> &visited, bool &check){
        visited[start] = true;
        if(start == end)check = true;
        if(check)return;
        for(auto i : mp[start]){
            if(visited[i] == false){
                division*=graph[start+"-"+i];
                dfs(graph, mp, i, end, division, visited, check);
                if(check)return;
                division/=graph[start+"-"+i];
            }
        }
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, double>graph;
        unordered_map<string, vector<string>>mp;
        vector<double>rst;
        
        // initialize the graph
        for(int i = 0; i < equations.size(); i++){
            graph[equations[i][0]+"-"+equations[i][1]] = values[i];
            graph[equations[i][1]+"-"+equations[i][0]] = 1/values[i];
            mp[equations[i][0]].push_back(equations[i][1]);
            mp[equations[i][1]].push_back(equations[i][0]);
        }
        
        
        for(int i = 0; i < queries.size(); i++){
            string start = queries[i][0];
            string end = queries[i][1];
            bool check = false;
            double division  = 1.0;
            map<string, bool>visited;
            if(mp.find(start) == mp.end() || mp.find(end) == mp.end()){
                rst.push_back(-1.0);
                continue;
            }
            if(start==end){
                check = true;
                rst.push_back(1.0);
            }
            else {
                dfs(graph, mp, start, end, division, visited, check);
                if(check)rst.push_back(division);
                else rst.push_back(-1.0);
            }
        }
        
        return rst;
    }
};