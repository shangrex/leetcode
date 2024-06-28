class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int tmp = prices[0];
        int rst = 0;
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] > tmp){
                rst += (prices[i] - tmp);
                tmp = prices[i];
            }
            else tmp = prices[i];
        }
        return rst;
    }
};