class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_buy = prices[0];
        int ret = 0;
        for(auto &p : prices){
            int t = p - min_buy;
            ret = max(ret, t);
            min_buy = min(min_buy, p);
        }
        return ret;
    }
};