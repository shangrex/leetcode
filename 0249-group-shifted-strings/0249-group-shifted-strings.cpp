class Solution {
public:

    string shift(string s){
        char diff = s[0] - 'a';
        // b - a = 1
        // 
        // c - 1
        // 'b' 2 - 25 + 26
        // -23 + 26 = 3
        for(auto &i : s){
            i = ((i - diff) + 26) % 26 + 'a';
        }
        return s;
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