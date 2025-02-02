class Solution {
public:
    /*
    Apporach 0. brute formce. Split the equal subset = sum of the subset equals to 
    Approach 1. DP top down
    memo[index][subsetsum]
    Approach 2. Bottom up. 
    dp[index][subsetsum]
    Apprach 3. 1-D DP
    */
    bool dfs(vector<int>& nums, vector<vector<int>>&memo, int idx, int target) {
        if(idx >= nums.size()) return false;
        if(target < 0) return false;
        if(target == 0) return true;
        if(memo[idx][target] != -1) return memo[idx][target];
        memo[idx][target] = dfs(nums, memo, idx+1, target-nums[idx]) || 
                                dfs(nums, memo, idx+1, target);
        return memo[idx][target];
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int target = accumulate(nums.begin(), nums.end(), 0);

        if(target & 1)
            return false;
        target /= 2;
        vector<vector<int>> memo(n+2, vector<int>(target+2, -1));
        return dfs(nums, memo, 0, target);
    }
};