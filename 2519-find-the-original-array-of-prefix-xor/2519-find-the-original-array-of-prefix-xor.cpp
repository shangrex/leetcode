class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> ret;
        int n = pref.size();
        ret.push_back(pref[0]);
        for(int i = 1; i < n; i++){
            ret.push_back(pref[i]^pref[i-1]);
        }
        return ret;
    }
};