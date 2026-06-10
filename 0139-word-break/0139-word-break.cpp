class Solution {
public:
    /*
    */
    unordered_map<string, int> mp;
    vector<int>dp;
    void backtrack(string &s, int idx){
        for(int i = 1; i+idx <= s.length(); i++){
            string tmpStr = s.substr(idx, i);
            if(mp.find(tmpStr) != mp.end() && dp[idx]){
                if(dp[i+idx] == 1) continue;
                // cout << i+idx << endl;
                dp[i+idx] = 1;
                backtrack(s, idx+i);
            }
        }
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        dp.resize(n+2, 0);
        for(auto &s : wordDict){
            mp[s] = 1;
        }
        int idx = 0;
        dp[0] = 1;
        backtrack(s, idx);
        return dp[n];
    }
};