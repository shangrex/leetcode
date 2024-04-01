class Solution {
public:
    /*
    method 1. bottom-up solution
        int change(int amount, vector<int>& coins) {
        vector<int>dp(amount+1, 0);
        dp[0] = 1;
        for(int i = 0; i < coins.size(); i++){
            for(int j = coins[i]; j <= amount; j++){
                dp[j] += dp[j - coins[i]];
            }
        }
        
        return dp[amount];
    }
    
    method 2. top-down solution & memorization
    */
    
    public:
    vector<vector<int>>memo;
    vector<int>coins;
    int dp(int amount, int index){
        // cout << amount << " " << index << endl;
        if(amount == 0)return 1;
        if(index == coins.size() || amount < 0)return 0;
        if(memo[index][amount] != -1)return memo[index][amount]; 
        // if(coins[index] > amount)return 0;
        
        // select coins[index]
        int sum1 = dp(amount - coins[index], index);
        // not select
        int sum2 = dp(amount, index+1);
        
        memo[index][amount] = sum1+sum2;
        return memo[index][amount];
    }
    
    int change(int amount, vector<int>& coins) {
        memo.assign(coins.size(), vector<int>(amount+1, -1));
        this->coins = coins;
        return dp(amount, 0);
        
    }
};