class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.length()+1, vector<int>(text2.length()+1));
        for(int i = 0; i <= text1.length(); i++)dp[i][0] = 0;
        for(int i = 0; i <= text2.length(); i++)dp[0][i] = 0;
        
        for(int i = 1; i <= text1.length(); i++){
            for(int j = 1; j <= text2.length(); j++){
                dp[i][j] = max({dp[i-1][j], dp[i][j-1]});
                int tmp = text1[i-1]==text2[j-1]?dp[i-1][j-1]+1:dp[i-1][j-1];
                dp[i][j] = max({dp[i][j], tmp});
            }
        }
        return dp[text1.length()][text2.length()];
    }
};