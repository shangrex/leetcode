
    class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> q;
        int ans = 1;
        q.push(intervals[0][1]);
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < q.top()) {
                ans++;
            } else {
                q.pop();
            }
            q.push(intervals[i][1]);
        }
        return ans;
    }
};