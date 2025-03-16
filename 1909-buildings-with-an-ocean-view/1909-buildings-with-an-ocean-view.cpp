class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int view = INT_MIN;
        vector<int> ret;
        for(int i = heights.size()-1; i >= 0; i--){
            if( heights[i] > view) {
                ret.push_back(i);
                view = heights[i];
            }
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};