class Solution {
public:
    /*
    Approach 1. use post order
    use post order to check if the subtree node to be add number or not
    */
    long long dfs(vector<vector<int>> &graph, vector<int>&cost, int node, int parent, int &ret){
        /*
        1->0->2
        */
        vector<int>score;
        cout << node << " " << parent << endl;
        for(auto i: graph[node]){
            if(i == parent)continue;
            score.push_back(dfs(graph, cost, i, node, ret));
            cout << score.back() << endl;
        }

        if(score.empty()) return cost[node];
        long long ma = *max_element(score.begin(), score.end());
        for(auto v : score){
            if(ma > v) ret++;
        }
        return ma+cost[node];
    }
    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        vector<vector<int>> graph(n);
        for(int i = 0; i < edges.size(); i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        int ret = 0;
        vector<long long> sum;
        dfs(graph, cost, 0, -1, ret);
        return ret;
    }
};