class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> rst;
        int i = 0;
        // find the fist section of the rst
        // if(newInterval[1] < intervals[i][0]){
        //     rst.push_back({newInterval});
        // }
        for(; i < intervals.size(); i++){
            // non overlapping
            if(newInterval[0] > intervals[i][1]){
                rst.push_back({intervals[i]});
            }
            else break;
        }
        
        int tmp_head = newInterval[0], tmp_tail = newInterval[1];
        for(; i < intervals.size(); i++){
            tmp_head = min(intervals[i][0], tmp_head);
            // overlapping
            if(newInterval[1] >= intervals[i][0]){
                tmp_tail = max(tmp_tail, intervals[i][1]);
            }
            else break;
        }
        rst.push_back({tmp_head, tmp_tail});
        
        for(; i < intervals.size(); i++){
            // non overlapping
            if(newInterval[1] < intervals[i][0]){
                rst.push_back({intervals[i]});
            }
            else if(newInterval[0] > intervals[i][1]){
                rst.push_back(newInterval);
            }
        }
        

        return rst;
    }
};