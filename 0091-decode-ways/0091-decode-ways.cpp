class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int>dp(n+1, 0) ,s2(n, 0);
        
        for(int i = 0; i < n; i++){
            s2[i] = s[i] - '0';
        }
        dp[n] = 1;
        if(s2[n-1] != 0)dp[n-1] = 1;
        for(int i = n-2; i >= 0; i--){
            if(s2[i] != 0){
                dp[i] += dp[i+1]; 
            }
            if((s2[i] == 1  && s2[i+1] >= 0) || (s2[i] == 2 && s2[i+1] < 7)){
                dp[i] += dp[i+2];
            }
        }
        return dp[0];
    }
};