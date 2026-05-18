class Solution {
public:
    /*
    Approach 1. Greedy. Always attend earliest events and with earlist end time

    */
    int maxEvents(vector<vector<int>>& events) {
        int maxDay = 0;
        for(int i  = 0; i < events.size(); i++){
            maxDay = max(maxDay, events[i][1]);
        }
        sort(events.begin(), events.end());
        // min heap
        priority_queue<int, vector<int>, greater<int>> pq;
        int ret = 0;
        for(int i = 1, j = 0; i <= maxDay; i++){
            while(j < events.size() && events[j][0] <= i){
                pq.push(events[j][1]);
                j++;
            }

            while(!pq.empty() && pq.top() < i){
                pq.pop();
            }
            if(!pq.empty()){
                // cout << i << endl;
                // cout << pq.top() << endl;
                pq.pop();
                ret++;
            }
        }    

        return ret;
    }
};