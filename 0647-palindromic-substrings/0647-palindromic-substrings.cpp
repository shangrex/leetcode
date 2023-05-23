class Solution {
public:
    /*
    See the longest palindromic string
    */
    int countSubstrings(string s) {
        int n = s.length(), rst = 0;
        vector<vector<bool>> dp(n, vector<bool>(n));
        
        for(int i = 0; i < n; i++){
            dp[i][i] = true;
            rst++;
        }
        
        for(int i = 1; i < n; i++){
            // special case aa
            if(s[i] == s[i-1]){dp[i-1][i] = true;rst++;}
            
            for(int j = i-2; j >= 0; j--){
                if(s[i] == s[j] && dp[j+1][i-1] == true){
                    dp[j][i] = true;
                    rst++;
                }
                else dp[j][i] = false;
            }
        }
        return rst;
    }
};