class Solution {
    /* 
    method: 1 basic idea
    int s = 0;
    int combinationSum4(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++){
            if(target == nums[i])s+=1;
            if(target>nums[i])combinationSum4(nums, target-nums[i]);
        }
        return s;
    }
    method 2: top-down
    record whether re-calculate the target number, and save the target number to dp-array (recursive solutions)
    
    method 3: bottom-up
    
    */
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int>dp(target+1, 0);
        dp[0] = 1;
        for(int i = 1; i <= target; i++){
            for(int j=0; j < nums.size(); j++){
                if(i >= nums[j]){
                    dp[i] += dp[i-nums[j]];
                }
            } 
        }
        return dp[target];
    }
};