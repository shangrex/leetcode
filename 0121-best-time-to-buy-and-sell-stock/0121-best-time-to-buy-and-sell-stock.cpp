class Solution {
public:
    /*
    Approach 1:
    Greedy approach
    to see the best profit, we must buy the current min stock and sell it
    so traverse the vector and sell in each index, and store the min prices 
    
    Approach 2:
    sliding window
    left pointer buy stock
    right pointer sell stock
    if left pointer is smaller move left
    if right pointer is bigger move right
    otherwise move left
    */
    int maxProfit(vector<int>& prices) {
        int rst = 0;
        int left = 0;
        int right = left+1;
        while(right < prices.size()){
            rst = max(rst, prices[right]-prices[left]);
            if(prices[right] < prices[left]){
                left = right;
            }
            else{
                right++;
            }
        }
        return rst;
    }
};