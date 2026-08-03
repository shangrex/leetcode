class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        // available tasks will store in pq
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int n = tasks.size();
        for(int i = 0; i < n; i++) tasks[i].push_back(i);
        sort(tasks.begin(), tasks.end());

        vector<int> ret;
        int idx = 0;
        long long curTime = 0;
        while(idx < n || pq.size()){
            if(pq.empty()){
                curTime = max(curTime, (long long)tasks[idx][0]);
            }

            while(idx < n && curTime >= tasks[idx][0]){
                // push the tasks into priroty queu since curTime is larger than enqueue time
                pq.push({tasks[idx][1], tasks[idx][2]});
                idx++;
            }


            auto [nxtTime, nxtIdx] =  pq.top();
            pq.pop();

            curTime += nxtTime;
            ret.push_back(nxtIdx);
        }

        return ret;
    }
};