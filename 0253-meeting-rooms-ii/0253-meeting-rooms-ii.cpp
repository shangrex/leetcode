class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        int ret = 0;
        int i = 0;
        while(i < intervals.size()){
            if(pq.empty()){
                ret++;
                pq.push(intervals[i][1]);
            }
            else {
                int tp = pq.top();
                if(tp <= intervals[i][0]){
                    pq.pop();
                    pq.push(intervals[i][1]);
                }
                else {
                    ret++;
                    pq.push(intervals[i][1]);
                }
            }
            i++;
        }
        return ret;
    }
};