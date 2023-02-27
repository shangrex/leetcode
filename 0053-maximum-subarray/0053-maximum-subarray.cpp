class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int rst = -1e4;
        vector<int>dp(nums.size());
        rst = dp[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            dp[i] = max(nums[i], nums[i]+dp[i-1]);
            rst = max(rst, dp[i]);
        }
        return rst;
    }
};