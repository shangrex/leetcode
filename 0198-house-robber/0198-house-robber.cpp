class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1, 0);
        dp[0] = 0;
        for(int i = 1; i <= nums.size(); i++){
            dp[i] = nums[i-1];
        }
        for(int i = 3; i <= nums.size(); i++){
            dp[i] = dp[i]+max(dp[i-2], dp[i-3]);
        }
        return max(dp[nums.size()], dp[nums.size()-1]);
    }
};