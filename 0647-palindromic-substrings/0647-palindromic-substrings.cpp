class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        
        int rst = n;
        for(int i = 0; i < n; i++){
                dp[i][i] = true;
        }
        
        for(int i = 0; i < n; i++){
            if(i > 0 && s[i-1] == s[i]){dp[i-1][i] = true;rst++;}
            
            for(int j = i-2; j >= 0; j--){
                if(s[j] == s[i] && dp[j+1][i-1]){
                    dp[j][i] = true;
                    rst++;
                }
            }
        }
        return rst;
    }
};