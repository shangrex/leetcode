class Solution {
    /*
    1 -> 1
    2 -> 1
    3 - > 2
    4 -> min(2, 2)
    */
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1, 0);
        if(amount==0)return 0;
        // initilize
        for(int i = 0; i < coins.size(); i++){
            if(amount>coins[i])dp[coins[i]]=1;
            if(amount==coins[i])return 1;
        }
        for(int i = 1; i <= amount; i++){
            if(dp[i] == 1){continue;}
            int tmp = INT_MAX, last = INT_MAX;
            bool flag = false;
            for(int j = 0; j < coins.size(); j++){
                if(coins[j]<i){
                    tmp = min(dp[i-coins[j]], last);
                    if(tmp==0)continue;
                    last = tmp;
                    flag = true;
                }
            }
            if(flag)dp[i] += (last+1);
        }
        if(dp[amount] == 0)return -1;
        else return dp[amount];
    }
};