class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b){
            return a[0] < b[0];
        });
        int left = intervals[0][0], right = intervals[0][1];
        
        
        // for(auto i : intervals)cout << i[0] << endl;
        vector<vector<int>> rst;
        
        for(int i = 0; i < intervals.size(); i++){
            if(intervals[i][0] <= right){
                right = max(right, intervals[i][1]);
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
};