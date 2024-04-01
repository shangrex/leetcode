class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int>dp(amount+1, 0);
        
        dp[0] = 1;
        
        // for(int i = 1; i <= amount; i++){
        //     for(int j = 0; j < coins.size(); j++){
        //         if(i-coins[j] >= 0)dp[i] += dp[i-coins[j]];
        //     }
        // }
        dp[0] = 1;
        for(int i = 0; i < coins.size(); i++){
            for(int j = coins[i]; j <= amount; j++){
                dp[j] += dp[j - coins[i]];
            }
        }
        
        for(int i = 0; i <= amount; i++){
            cout << dp[i] << " ";
        }
        
        return dp[amount];
    }
};