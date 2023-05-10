class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int rst = 0;
        if(intervals.size() == 0)return 0;
        sort(intervals.begin(), intervals.end(), [](const vector<int>&a, const vector<int>&b){
            if(a[0] < b[0])return true;
            else if(a[0] == b[0] && a[1] < b[1])return true;
            else return false;
        });
        
        int tmp_head = intervals[intervals.size()-1][0];
        for(int i = intervals.size()-2; i >= 0; i--){
            //cout << tmp_head << endl;
            if(tmp_head < intervals[i][1]){
                rst++;
                continue;
            }
            tmp_head = intervals[i][0];
        }
        
        return rst;
    }
};