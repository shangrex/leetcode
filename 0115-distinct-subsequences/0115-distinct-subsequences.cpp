class Solution {

public:
    unordered_map<string, int> memo;    
    int numDistinct(string s, string t) {
        if(s == t || t.empty()) return 1;
        if(s.size() < t.size()) return 0;
        int n = s.size(), m = t.size();
        string key = s + "," + t;
        if(memo.find(key) != memo.end()) return memo[key];

        int rst = numDistinct(s.substr(0, n-1), t);
        // cout << key << rst << endl;
        if(s[n-1] == t[m-1]){
            rst += numDistinct(s.substr(0, n-1), t.substr(0, m-1));
        }

        memo[key] = rst;
        // cout << key << rst << endl;
        return rst;
    }
};