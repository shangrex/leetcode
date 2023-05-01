class Solution {
public:
    // 0 means not visited
    // 1 means is being visited
    // 2 means has been visited
    vector<int> visited;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int> >graph(numCourses, vector<int>());
        visited.assign(numCourses, 0);
        // build graph
        for(int i = 0; i < prerequisites.size(); i++){
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
  
        // select all nodes and dfs to check if there is cycle
        for(int i = 0; i < numCourses; i++){
            if(visited[i] == 0){
                if(dfs(i, graph))return false;
            }
        }        
        return true;
    }
    // check if there is cycle
    bool dfs(int n, vector<vector<int> > &graph){
        // cout << visited[0] << " " << visited[1];
        visited[n] = 1;
        for(int i = 0; i < graph[n].size(); i++){
            // if is being visited then there is a cycle
            if(visited[graph[n][i]] == 1)return true;
            else if(visited[graph[n][i]] == 0){
                if(dfs(graph[n][i], graph))return true;
            }
        }
        visited[n] = 2;
        return false;
    }
};