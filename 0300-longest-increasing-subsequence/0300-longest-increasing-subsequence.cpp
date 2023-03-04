class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size()+1, 1);
        int rst = 1;
        for(int i = 1; i < nums.size(); i++){
            for(int j = 1; j <= i; j++){
                if(nums[i-j] < nums[i])
                    dp[i] = max(dp[i-j]+1, dp[i]);
            }
            rst = max(dp[i], rst);
        }
        return rst;
    }
};