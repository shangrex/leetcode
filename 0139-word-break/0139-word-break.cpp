class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool>dp(s.size()+1, false);
        dp[0] = true;
        for(int i = 1; i <= s.length(); i++){
            for(auto j : wordDict){
                if(i >= j.length()){
                    if(dp[i-j.length()]){
                        string tmp = s.substr(i-j.length(), j.length());
                        if(find(wordDict.begin(), wordDict.end(), tmp) != wordDict.end()){dp[i] = true;break;}
                        
                    }   
                }
            }
        }
        return dp[s.length()];
    }
};