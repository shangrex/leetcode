class Solution {
public:
    /*
    BFS + adding route as a queue element
    */
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> visited;

        queue<int>q;

        for(int i = 0; i < routes.size(); i++){
            for(int j = 0; j < routes[i].size(); j++){
                graph[routes[i][j]].push_back(i);
            }
        }
        // for(auto &i : graph[source]){
        //     q.push(i);
        //     visited[i] = 1;
        // }
        q.push(source);
        visited[source] = 1;
  
        int level = 0;
        while(!q.empty()){
            int n = q.size();
            level ++;
            for(int i = 0; i < n; i++){
                int cur = q.front();
                q.pop();
                if(cur == target){
                    return level-1;
                }
                for(auto &j : graph[cur]){
                    for(auto &k : routes[j]){
                        if(visited.find(k) == visited.end()){
                            visited[k] = 1;
                            q.push(k);
                        }
                    }
                    routes[j].clear();
                }

            }
        }

        return -1;
    }
};