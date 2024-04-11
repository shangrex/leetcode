class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<int>dp(s.size()+1, 0);
        unordered_map<int, vector<string>> mp;
        
        dp[0] = 1;
        mp[0].push_back("");
        
        for(int i = 1; i <= s.length(); i++){
            for(int j = 0; j < wordDict.size(); j++){
                int w_l = wordDict[j].length();
                if(i >= w_l && dp[i-w_l] == 1){
                    string tmp = s.substr(i-w_l, w_l);
                    if(tmp == wordDict[j]){
                        dp[i] = 1;
                        for(auto k : mp[i-w_l]){
                            if(k == "")mp[i].push_back(tmp);
                            else mp[i].push_back(k + " " + tmp);
                        }
                    }
                }
            }
        }
        
        return mp[s.length()];
    }
};