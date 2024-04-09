class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>>pq;
        
        int rst = 0;
        for(int i = 0; i < intervals.size(); i++){
            if(pq.empty()){
                rst++;
                pq.push(intervals[i][1]);
            }
            else if(intervals[i][0] < pq.top()){
                pq.push(intervals[i][1]);
                rst++;
            }
            else {
                pq.pop();
                pq.push(intervals[i][1]);
            }
            
        }
        return rst;
    }
};