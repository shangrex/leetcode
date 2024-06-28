class Solution {
public:
    int countprofit(vector<int>&prices, int idx, bool buy, int buy_cnt, int k, vector<vector<vector<int>>>&memo){
        if(idx >= prices.size() || buy_cnt >= k){
            return 0;
        }
        if(memo[idx][buy][buy_cnt] != -1){
            return memo[idx][buy][buy_cnt];
        }
        // none operation
        int hold = countprofit(prices, idx+1, buy, buy_cnt, k, memo);
        int money;
        if(buy){
            // buy operation
            money = -prices[idx] + countprofit(prices, idx+1, false, buy_cnt, k, memo);
        }
        else {
            money = prices[idx] + countprofit(prices, idx+1, true, buy_cnt+1, k, memo);
        }
        memo[idx][buy][buy_cnt] = max(hold, money);
        return max(hold, money);
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>>memo(prices.size(), vector<vector<int>>(2, vector<int>(k+1, -1)));
        return countprofit(prices, 0, true, 0, k, memo);
    }
};