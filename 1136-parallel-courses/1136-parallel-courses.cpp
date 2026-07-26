class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<int> indegree (n+1, 0);
        vector<vector<int>> graph(n+1);
        vector<int> visited(n+1, 0);
        for(int i = 0; i < relations.size(); i++){
            graph[relations[i][0]].push_back(relations[i][1]);
            indegree[relations[i][1]]++;
        }

        queue<int> q;
        for(int i = 1; i <= n; i++){
            if(indegree[i] == 0) {
                q.push(i);
                visited[i] = 1;
            }
        }


        int level = 0;
        while(!q.empty()){
            int m = q.size();
            level++;
            for(int i = 0; i < m; i++){
                int node = q.front();
                q.pop();

                for(int i = 0; i < graph[node].size(); i++){
                    if(visited[graph[node][i]] == 1) {
                        return -1;
                    }
                    if(--indegree[graph[node][i]] == 0){
                        q.push(graph[node][i]);
                        visited[graph[node][i]] = 1;
                    }
                }
            }
        }

        for(int i = 1; i <= n; i++){
            if(visited[i] == 0) return -1;
        }
        return level;
    }
};