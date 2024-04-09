class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>&a, const vector<int>&b){
            if(a[1] < b[1]){
                return true;
            }
            else if(a[1] > b[1]){
                return false;
            }
            else if(a[0] < b[0]){
                return true;
            }
            else return false;
        });
        
        int cnt = 0, prev_index = 0;
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] < intervals[prev_index][1]){
                cnt++;
            }
            else prev_index = i;
        }
        return cnt;
    }
};