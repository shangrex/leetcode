class Solution {
public:
    /*
    Approach 2. Topology sort
    indegree 1 -> the leaf node that can start to to check if connect or not
    */

    long long dfs(int idx, int parent_idx, vector<vector<int>>&graph, vector<int>&values, long long sum, int &ans, int k){
        sum = 0;
        for(int i = 0; i < graph[idx].size(); i++){
            if(graph[idx][i] != parent_idx){
                sum += dfs(graph[idx][i], idx, graph, values, sum, ans, k);
            }
        }
        long long tmp = sum + values[idx];
        // values[idx] += sum;
        if(tmp % k == 0){
            ans++;
            return tmp;
        }
        
        return tmp;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        // value -> child sum
        // total sum
        
        // step1 construct graph
        vector<vector<int>> graph(n);
        
        for(int i = 0; i < edges.size(); i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        int ans = 0;
        // calculate new value (sum of the substree)
        dfs(0, -1, graph, values, 0, ans, k);
        return ans;
    }
};