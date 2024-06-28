class Solution {
public:
    int countprofit(vector<int>&prices, int idx, bool buy, vector<vector<int>>&memo){
        if(idx >= prices.size()){
            return 0;
        }
        
        if(memo[idx][buy] != -1){
            return memo[idx][buy];
        }
        // hold
        int hold = countprofit(prices, idx+1, buy, memo);
        int money;
        if(buy){
            // buy
            money =  -prices[idx] + countprofit(prices, idx+1, false, memo);
        }
        else{
            // sell
            money = prices[idx] + countprofit(prices, idx+2, true, memo);
        }
        memo[idx][buy] = max(hold, money);
        return memo[idx][buy];
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>memo(prices.size(), vector<int>(2, -1));
        return countprofit(prices, 0, true, memo);
    }
};