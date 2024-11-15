class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size() == 0){
            return {newInterval};
        }
        vector<vector<int>> rst;
        int n = intervals.size();
        int i = 0;
        
        // case 1 rst push left part
        while(i < n && intervals[i][1] < newInterval[0]){
            rst.push_back(intervals[i]);
            i++;
        }
        
        // case 2 merge part
        int left = newInterval[0], right = newInterval[1];
        while(i < n && intervals[i][0] <= newInterval[1]){
            left = min(intervals[i][0], left);
            right = max(right, intervals[i][1]);
            i++;
        }
        rst.push_back({left, right});
        
        // case 3 rst push right part
        while(i < n && intervals[i][0] > newInterval[1]){
            rst.push_back(intervals[i]);
            i++;
        }
        
        return rst;
    }
};



/*
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size() == 0){
            return {newInterval};
        }
        int left = newInterval[0], right = newInterval[1];
        
        vector<vector<int>>rst;
        if(newInterval[1] < intervals[0][0]){
            rst.push_back({newInterval});
            left = intervals[0][0];
            right = intervals[0][1];
        }
        
        int i = 0;        
        for(;i < intervals.size(); i++){
            if(intervals[i][1] < newInterval[0]){
                rst.push_back(intervals[i]);
            }
            else break;
        }
        
        for(; i < intervals.size(); i++){
            if(intervals[i][1] >= newInterval[0] && intervals[i][0] <= newInterval[1]){
                // overlape
                left = min(left, intervals[i][0]);
                right = max(newInterval[1], intervals[i][1]);
            }
            else if(intervals[i][0] > right){
                rst.push_back({left, right});
                left = intervals[i][0];
                right = intervals[i][1];
            }
        }
        rst.push_back({left, right});
        

        
        return rst;
    }
*/