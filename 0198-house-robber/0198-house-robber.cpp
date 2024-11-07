class Solution {
public:
    /*
    Approach 1. bottom-up
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1, 0);
        dp[1] = nums[0];
        for(int i = 2; i <= nums.size(); i++){
            dp[i] = max(dp[i-1], dp[i-2]+nums[i-1]);
        }
        return dp[nums.size()];
    }
    
    Approach 2. top-down
    int helper(int index, vector<int>&nums, vector<int>&dp){
        if(index >= nums.size())return 0;
        if(dp[index] != -1)return dp[index];
        
        dp[index] = max(nums[index] + helper(index+2, nums, dp), helper(index+1, nums, dp));
        return dp[index];
    }
    
    int rob(vector<int>&nums) {
        if(nums.size() == 1) return nums[0];
        vector<int>dp(nums.size(), -1);   
        return helper(0, nums, dp);
    }
    */
    
    int helper(int idx, vector<int>&nums, vector<int>&dp){
        if(idx > nums.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        dp[idx] = max(nums[idx-1] + helper(idx+2, nums, dp), helper(idx+1, nums, dp));
        return dp[idx];
    }
    
    int rob(vector<int>&nums) {
        int n = nums.size();
        vector<int>dp(n+1, -1);
        return helper(1, nums, dp);
    }
};