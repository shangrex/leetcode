class Solution {
public:
    /*  baab
    palidrome dp[i][i] =. true
              dp[i-1][i] = true if s[i-1] == s[i]
    dp[i-1][i+1]  then s[i-1] == s[i+1]
    */
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
            
        for(int i = 0; i < n; i++){
            dp[i][i] = true;
        }
        
        
        int left = 0, max_length = 1;
        for(int i = 0; i < n; i++){
            if(i > 0 && s[i-1] == s[i]) {
                dp[i-1][i] = true;
                if(max_length < 3) {left = i-1, max_length = 2;}
            }
            
            for(int j = i-2; j >= 0; j--){
                if(s[j] == s[i] && dp[j+1][i-1]){
                    dp[j][i] = true;
                    if(max_length < i-j+1) {left = j; max_length = i-j+1;}
                }
            }
        }
        
        return s.substr(left, max_length);
        
        
        
    }
};