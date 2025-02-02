class Solution {
public:
    /*
    Apporach 0. brute formce. Split the equal subset = sum of the subset equals to 
    ```
    bool dfs(vector<int>& nums, int sum, int idx, int target)(
        if (sum == target)
            return true;
        if (idx >= nums.size()) {
            return false;
        }
        if (sum > target)
            return false;
        
        // 1. without consider nums[idx]
        return dfs(nums, idx + 1, sum, target) ||
        // 2. consider nums[idx]
               dfs(nums, idx + 1, sum + nums[idx], target);
    )
    ```
    Approach 1. DP top down. The overall performance is the best, since we terminate the search
    once we find the memo
    time complexity m*n
    space complexity n + m*n
    memo[index][subsetsum]
    ```
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
    ```
    Approach 2. Bottom up. 
    dp[index][subsetsum]
    Apprach 3. 1-D DP
    be careful the overwrite problem. In 2-D, it two loop can start from begining, since
    it will not overlap. However, in 1-D. It need to loop backward to prevent loop problem.
    Since dp[j] depends on depends[j-1], depends[j-1] ... depends[0], so it is safe to start 
    from right
    */
    bool dfs(vector<int>& nums, vector<int>&memo, int idx, int target) {
        if(idx >= nums.size()) return false;
        if(target < 0) return false;
        if(target == 0) return true;
        if(memo[target] != -1) return memo[target];
        memo[target] = dfs(nums, memo, idx+1, target-nums[idx]) || 
                                dfs(nums, memo, idx+1, target);
        return memo[target];
    }

    bool canPartition(vector<int>& nums) {
        // int n = nums.size();
        // int target = accumulate(nums.begin(), nums.end(), 0);

        // if(target & 1)
        //     return false;
        // target /= 2;
        // vector<int> memo(target+2, -1);
        // return dfs(nums, memo, 0, target);
        
        // 1-D DP
        int n = nums.size();
        int target = accumulate(nums.begin(), nums.end(), 0);
        if(target & 1) return false;
        target /= 2;
        vector<bool>dp(target+2, 0);
        dp[0] = true;
        // this is coin count dp 518
        // for(int i = 1; i <= target; i++){
        //     for(auto j : nums){
        //         if(i-j >= 0)
        //             dp[i] = dp[i] || dp[i-j];
        //         else dp[i] = dp[i];
        //     }
        // }
        // wtf
        for(auto curr : nums){
            for(int j = target; j >= curr; j--){
                dp[j] = dp[j] || dp[j-curr];
            }
        }
        return dp[target];
    }
};