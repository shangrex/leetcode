class Solution {
public:
    /*
        vector<vector<int>> rst;
        int i = 0;
        // find the fist section of the rst
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
            else break;
        }
        

        return rst;
    */
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> rst;
        int i = 0;
        
        // add non overlappint part into head of rst
        while(i < intervals.size()){
            if(intervals[i][1] < newInterval[0]){
                rst.push_back(intervals[i]);
                i++;
            }
            else break;
        }
        
        // add new Interval into rst
        
        while( i < intervals.size() && newInterval[1] >= intervals[i][0] && newInterval[0] <= intervals[i][1]){
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        rst.push_back(newInterval);
        
        // add non overlapping part into the end of rst
        while( i < intervals.size()){
            rst.push_back(intervals[i]);
            i++;
        }
        
        return rst;
    }
};