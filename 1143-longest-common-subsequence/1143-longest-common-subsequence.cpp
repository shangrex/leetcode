class Solution {
public:
    /*
      a b c d e
     a1 1 1 1 1
     c1 1 2 2 2
     e1 1 2 2 3
    
    */
    
    
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.length()+1, vector<int>(text2.length()+1, 0));    
        for(int i = 1; i <= text1.length(); i++){
            for(int j = 1; j <= text2.length(); j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp[text1.length()][text2.length()];
    }
};