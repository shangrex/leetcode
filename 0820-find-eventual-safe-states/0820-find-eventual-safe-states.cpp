class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        
        vector<int>outdegree(n, 0);
        for(int i = 0; i < graph.size(); i++){
            for(auto j : graph[i]){
                outdegree[i]++;
            }
        }
        vector<vector<int>> rev_graph(n);
        for(int i = 0; i < graph.size(); i++){
            for(auto j : graph[i]){
                rev_graph[j].push_back(i);
            }
        }
        
        set<int>rst;
        vector<int>visited(n, 0);
        queue<int> q;

        for(int i = 0; i < n; i++){
            if(outdegree[i] == 0){
                q.push(i);
                rst.insert(i);
                visited[i] = 1;
            }
        }

        while(!q.empty()){
            int q_size = q.size();
            for(int i = 0 ; i < q_size; i++){
                int t = q.front();
                q.pop();
                for(auto neighbor: rev_graph[t]){
                    if(--outdegree[neighbor] == 0 && visited[neighbor] == 0){
                        q.push(neighbor);
                        rst.insert(neighbor);
                        visited[neighbor] = 1;
                    }
                }
            }
          
        }

        vector<int>ans;
        for(auto i : rst){
            ans.push_back(i);
        }

        return ans;
    }
};