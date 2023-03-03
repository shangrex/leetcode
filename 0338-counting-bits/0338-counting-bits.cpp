class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>dp(n+1);
        if(n==0)return {0};
        if(n==1)return {0, 1};
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 1;i <= n/2; i++){
            if(i*2<=n)dp[i*2] = dp[i];
            if(i*2+1<=n)dp[i*2+1] = dp[i]+1;
        }
        return dp;
    }
};