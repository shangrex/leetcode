class Solution {
public:
    /*
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
    */
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for(auto &str : strs){
            string tmpStr = str;
            sort(tmpStr.begin(), tmpStr.end());
            mp[tmpStr].push_back(str);
        }

        vector<vector<string>> ret;
        for(auto &i : mp){
            vector<string> tmpVec;
            for(auto &j : i.second){
                tmpVec.push_back(j);
            }
            ret.push_back(tmpVec);
        }
        return ret;
    }
};