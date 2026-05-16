/*
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Peeling layer one by one
        // If there still exists element cannot be remove -> impossible

        //Indegree for each node
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0);
        for (const auto& prerequisite : prerequisites)
        {
            inDegree[prerequisite[0]]++;
            graph[prerequisite[1]].push_back(prerequisite[0]);
        }
        
        queue<int> q;
        vector<bool> visited(numCourses, false);
        for (int i = 0; i < numCourses; i++)
            if (!inDegree[i])
            { 
                q.push(i);
                visited[i] = true;
            }
        
        // Peeling layer for topological sort
        while (!q.empty())
        {
            int node = q.front();   q.pop();
            for (int neighbor : graph[node])
                if (!--inDegree[neighbor])
                {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
        }
        
        //Check still left nodes
        for (int v : visited)
            if (!v) return false;
        return true;
    }
};
*/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        // vector<bool> visited(numCourses);
        for(int i = 0; i < prerequisites.size(); i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }

        priority_queue<int> pq;
        for(int i = 0; i < indegree.size(); i++){
            if(indegree[i] == 0) pq.push(i);
        }

        while(!pq.empty()){
            int node = pq.top();
            pq.pop();
            for(int i = 0; i < graph[node].size(); i++){
                if(--indegree[graph[node][i]] == 0){
                    pq.push(graph[node][i]);
                }
            }
        }

        for(int i = 0; i < numCourses; i++){
            if(indegree[i] != 0) return false;
        }
        return true;
    }
};