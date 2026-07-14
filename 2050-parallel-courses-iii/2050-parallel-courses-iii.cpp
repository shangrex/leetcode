class Solution {
public:
    /*
    Topology sort 
    */
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        // find longest topology route
        // topology sort

        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);
        queue<int>q;

        for(auto & edge : relations){
            int x = edge[0]-1;
            int y = edge[1]-1;
            graph[x].push_back(y);
            indegree[y]++;
        }


        vector<int> maxTime(n, 0);

        for(int i = 0;i < n; i++){
            if(indegree[i] == 0){
                q.push(i);
                maxTime[i] = time[i];
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int i = 0; i < graph[node].size(); i++){
                int nxtNode = graph[node][i];
                maxTime[nxtNode] = max(maxTime[nxtNode], time[nxtNode]+maxTime[node]);

                if(--indegree[nxtNode] == 0){
                    q.push(nxtNode);
                }
            }
        }

        int ret = 0;
        for(int i = 0; i < n; i++){
            ret = max(ret, maxTime[i]);
        }
        return ret;
    }
};