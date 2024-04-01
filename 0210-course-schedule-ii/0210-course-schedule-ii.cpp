class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numCourses, vector<int>());
        vector<int>indegree(numCourses, 0);
        
        for(auto i : prerequisites){
            indegree[i[0]]++;
            graph[i[1]].push_back(i[0]);
        }
        
        queue<int>q;
        
        for(int i = 0; i < indegree.size(); i++){
            if(indegree[i] == 0)q.push(i);
        }
        
        vector<int>ans;
        while(!q.empty()){
            int t = q.front();    
            ans.push_back(t);
            q.pop();
            
            for(auto i : graph[t]){
                if(--indegree[i] == 0){
                    q.push(i);
                }
            }
        }
        
        if(ans.size() != numCourses)return {};
        return ans;
        
    }
};