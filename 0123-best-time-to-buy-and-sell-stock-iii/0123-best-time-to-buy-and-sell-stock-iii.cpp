class Solution {
public:
    int countprofit(vector<int>&prices, int idx, bool buy, int buy_cnt, vector<vector<vector<int>>>&memo){
        if(idx >= prices.size() || buy_cnt >= 2){
            return 0;
        }
        //[3,3,5,0,0,3,1,4]
        if(memo[idx][buy][buy_cnt] != -1){
            return memo[idx][buy][buy_cnt];
        }
        // non operation
        int hold = countprofit(prices, idx+1, buy, buy_cnt, memo);
        int money;

        if(buy && buy_cnt < 2){
            // buy operation
            money = -prices[idx] + countprofit(prices, idx+1, false, buy_cnt, memo);
        }
        else {
            // sell operation
            money = prices[idx] + countprofit(prices, idx+1, true, buy_cnt+1, memo);
        }
        memo[idx][buy][buy_cnt] = max(hold, money);

        // cout << idx << " " << buy << " " <<  memo[idx][buy] << " " << buy_cnt << endl;
        return memo[idx][buy][buy_cnt];
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> memo(prices.size(), vector<vector<int>>(2, vector<int>(4, -1)));
        return countprofit(prices, 0, true, 0, memo);
    }
};