class Solution {
public:
    int helper(int index, int end, vector<int>&nums, vector<int>&dp){
        if(index > end)return 0;
        if(dp[index] != -1)return dp[index];
        dp[index] = max(helper(index+1, end, nums, dp), nums[index] + helper(index+2 ,end, nums, dp));
        // cout << index << " " << dp[index] << " " << end << endl;
        return dp[index];
    }
    
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(), -1);
        if(nums.size()==1)return nums[0];
        int a = helper(0, nums.size()-2, nums, dp);
        vector<int>dp2(nums.size(), -1);        
        int b = helper(1,nums.size()-1, nums, dp2);
        return max(a, b);
    }
};