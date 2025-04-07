class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>mp;

        for(auto &s : strs){
            string t = s;
            sort(t.begin(), t.end());
            mp[t].push_back(s);
        }

        vector<vector<string>> ret;
        for(auto it : mp){
            ret.push_back(it.second);
        }
        return ret;
    }
};