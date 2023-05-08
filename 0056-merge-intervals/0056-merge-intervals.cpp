class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> rst;
        if(intervals.size() == 0)return rst;
        
        sort(intervals.begin(), intervals.end(), [](const vector<int>&a, const vector<int>&b){
            return a[0] < b[0];
        });
        
        int tmp_head = intervals[0][0], tmp_tail = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++){
            if(tmp_tail >= intervals[i][0]){
                tmp_tail = max(intervals[i][1], tmp_tail);
                continue;
            }
            else {
                rst.push_back({tmp_head, tmp_tail});
                tmp_head = intervals[i][0];
                tmp_tail = intervals[i][1];
            }
        }
        rst.push_back({tmp_head, tmp_tail});
        return rst;
    }
};