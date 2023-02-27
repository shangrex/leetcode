class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int rst = -10, tmp_max = -10;
        vector<vector<int>>dp(2, vector<int>(nums.size()));
        dp[0][0] = rst = dp[1][0] = nums[0];
        for(int i = 1;i < nums.size(); i++){
            tmp_max = max({nums[i], nums[i]*dp[1][i-1], nums[i]*dp[0][i-1]});
            rst = max(rst, tmp_max);
            // max subarray value
            dp[1][i] = max({1, dp[1][i-1]*nums[i], nums[i], dp[0][i-1]*nums[i]});
            // min subarray value
            dp[0][i] = min({dp[0][i-1]*nums[i], nums[i], dp[1][i-1]*nums[i]});
        }
        return rst;
    }
};