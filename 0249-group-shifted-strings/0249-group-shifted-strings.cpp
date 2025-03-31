class Solution {
public:

    string shift(string s){
        char diff = s[0] - 'a';
        string ret = "";
        for(int i = 1; i < s.length(); i++){
            ret += (s[i] - s[i-1] + 26)%26+'a';
        }
        return ret;
    }

    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>>mp;

        for(auto &s : strings){
            string t = shift(s);
            mp[t].push_back(s);
        }

        vector<vector<string>> rst;
        for(auto it : mp){
            vector<string> tmp;
            for(auto j : it.second){
                tmp.push_back(j);
            }
            rst.push_back(tmp);
        }
        return rst;
    }
};