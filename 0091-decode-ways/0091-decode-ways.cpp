class Solution {
public:
    int numDecodings(string s) {
        // p(n-1)+p'(n-2)
        int rst = 0;
        vector<int> s_tmp(s.length()+1, 0), dp(s.length()+1, 0);
        dp[s.length()]=1;
        // transform string to int number in vector
        for(int i = 0; i < s.length(); i++){
            s_tmp[i] = int(s[i])-'0';
        }
        for(int i = s.length()-1; i >= 0; i--){
            if(s_tmp[i] != 0){
                dp[i]+=dp[i+1];
            }
            if(i < s.length()-1){
                if((s_tmp[i] == 1) || (s_tmp[i] == 2 && s_tmp[i+1] < 7) ){
                    dp[i] += dp[i+2];
                }
            }
        }
        // cout << dp[0] << endl;
        return dp[0];
    }
};