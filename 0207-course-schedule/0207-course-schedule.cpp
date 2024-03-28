class Solution {
public:
    // construct graph and dfs traverse, if there is cycle then return true
    // otherwise the result is false
    
    public:
    vector<int>visited;
    vector<vector<int>> graph;
    void dfs(int cur, bool &rst){
        if(visited[cur] == 1)return;
        visited[cur] = 2;
        for(int i = 0; i < graph[cur].size(); i++){
            if(visited[graph[cur][i]] == 2){
                rst = false;
                return;
            }
            dfs(graph[cur][i], rst);
        }
        visited[cur] = 1;
        return;
    }
    // 0 never visited
    // 1 has been visited
    // 2 is visiting
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph.assign(numCourses, vector<int>());
        // construct the graph
        for(int i = 0; i < prerequisites.size(); i++){
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        bool rst = true;
        visited.assign(numCourses, 0);
        for(int i = 0; i < numCourses; i++){
            if(visited[i] == 1)continue;
            dfs(i, rst);
            if(!rst)return rst;
        }
        return rst;
    }
};