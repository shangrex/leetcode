class Solution {
public:
    /*
    1. three dimension top down dp
    dp[i][j][k]

    bool valid(string s, int l, int r, int k, vector<vector<int>>& dp){
        if(dp[l][r] != -1) return dp[l][r];
        if(l >= r) return true;

        bool flag = false;
        if(s[l] != s[r]){
            if(k > 0){
                flag |= valid(s, l+1, r, k-1, dp) || valid(s, l, r-1, k-1, dp);
            }
            else {
                dp[l][r] = false;
                return false;
            }
        }
        else {
            flag |= valid(s, l+1, r-1, k, dp);
        }
        dp[l][r] = flag;
        return flag;
    }

    bool isValidPalindrome(string s, int k) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return valid(s, 0, s.length()-1, k, dp);
    }
    */
    int valid(string &s, int l, int r, vector<vector<int>>& dp){
        if(l == r) return 0;
        if(l == r-1){
            return s[l] != s[r];
        }
        if(dp[l][r] != -1) return dp[l][r];

        if(s[l] != s[r]){
            dp[l][r] = 1 + min(valid(s, l+1, r, dp), valid(s, l, r-1, dp));
        }
        else {
            dp[l][r] = valid(s, l+1, r-1, dp);
        }

        return dp[l][r];
    }

    bool isValidPalindrome(string s, int k) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return valid(s, 0, s.length()-1, dp) <= k ? true : false;
    }
};