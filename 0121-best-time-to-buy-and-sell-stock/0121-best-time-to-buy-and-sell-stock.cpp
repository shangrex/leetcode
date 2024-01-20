class Solution {
public:
    /*
    int rst = 0, mi = 1e4+1;
    for(int i = 0; i < prices.size(); i++){
        mi = mi<prices[i]?mi:prices[i];
        rst = max(rst, prices[i]-mi);
    }
    return rst;
    */
    int maxProfit(vector<int>& prices) {
        int  min_value = prices[0], rst = 0;
        for(int i = 0; i < prices.size(); i++){
            rst = max(rst, prices[i]-min_value);
            min_value = min(min_value, prices[i]);
        }
        return rst;
    }
};