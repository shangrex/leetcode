class Solution {
public:
    /*
    approach 1: two pointer
        should consider two case, the odd length and even length (or use other ways to check the same continuous charactrers)
        x2 x1 a y1 y2 -> compare x1 ,y1 if it is the same then compare x2 ,y2 and so on
    approach 2: DP
        dp[start, end] inclusive means the boolen valuse of palindromic
        start+1 = end, start == end is true 
        start+2 = end, start == end && start+1, end-1 is true
        start+3 = end, start
    
    */
    string longestPalindrome(string s) {
        string rst;
        int n = s.length();
        vector<vector<bool>>dp(n, vector<bool>(n));
        
        // initialize
        for(int i = 0; i < n; i++){
            dp[i][i] = true;
        }
        // state transition
        for(int i = 1; i < n; i++){
            if(s[i] == s[i-1])dp[i-1][i] = true;
            for(int j = i-2; j >= 0; j--){
                if(s[i] == s[j] && dp[j+1][i-1] == true)dp[j][i] = true;
                else dp[j][i] = false;
            }
        }
        
    
        // find the longest palindromic substring
        int rst_start = 0, rst_length = 0, tmp_start = 0, tmp_length = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(dp[i][j] == true && tmp_length < j-i+1){
                    tmp_start = i;
                    tmp_length = j-i+1;
                }
            }
            if(tmp_length > rst_length){
                rst_length = tmp_length;
                rst_start = tmp_start;
            }
            tmp_length = 0;
        }
        rst = s.substr(rst_start, rst_length);
        return rst;
    }
};