class Solution {
public:
    /*
    Approach 1. DP
    dp[i] = max(dp[i], dp[0~i-1]+1)
    
    Approach 2. Use a sub array to record the previous longes and smallest value
    
    */
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size()+1, 1);
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        
        int rst = 0;
        for(int i = 0; i < nums.size(); i++){
            rst = max(rst, dp[i]);
        }
        return rst;
    }
};