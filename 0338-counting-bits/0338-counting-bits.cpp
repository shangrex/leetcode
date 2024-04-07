class Solution {
public:
    /*
    Approach 1.
    use __builtin_popcount
    */
    vector<int> countBits(int n) {
        if(n==0)return {0};
        if(n==1)return {0, 1};
        vector<int>dp(n+1, 0);
        dp[0] = 0;
        dp[1] = 1;
        
        for(int i = 2; i <= n; i++){
            dp[i] = dp[i>>1] + (i%2);
        }
        
        return dp;
    }
};