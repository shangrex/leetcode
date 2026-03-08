class Solution {
public:
    /*
    approach 1. sort
    appraoch 2.
    */
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int tmp_min = INT_MAX;
        for(int i = 1; i < arr.size(); i++){
            tmp_min = min(tmp_min, arr[i] - arr[i-1]);
        }

        vector<vector<int>> ret;
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] - arr[i-1] == tmp_min)ret.push_back({arr[i-1], arr[i]});
        }
        return ret;
    }
};