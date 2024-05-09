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
    */
  
    void helper(int index, vector<int>&nums, vector<int>&dp){
        if(index >= nums.size())return;
        
        if(index > 1)
            dp[index] = max(nums[index] + dp[index-2], dp[index-1]);
        else if(index == 1){
            dp[index] = max(dp[0], nums[1]);
        }
        else
            dp[index] = nums[index];
        
        helper(index+1, nums, dp);
    }
    
    int rob(vector<int>&nums) {
        if(nums.size() == 1) return nums[0];
        vector<int>dp(nums.size(), 0);   
        helper(0, nums, dp);
        return dp[nums.size()-1];
    }
};