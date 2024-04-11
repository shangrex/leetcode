class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>dp(s.size()+1, 0);
        dp[0] = 1;
        
        for(int i = 1; i <= s.length(); i++){
            for(int j = 0; j < wordDict.size(); j++){
                int w_l = wordDict[j].length();
                if(i >= w_l && dp[i-w_l] == 1){
                    string tmp = s.substr(i-w_l, w_l);
                    if(tmp == wordDict[j]){
                        dp[i] = 1;
                    }
                }
            }
        }
        
        return dp[s.length()];
    }
};