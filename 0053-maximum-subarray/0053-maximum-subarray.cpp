class Solution {
public:
/*
        vector<int>dp(nums.size()+1, 0);
        int rst = INT_MIN;
        dp[0] = 0;
        for(int i = 0; i < nums.size(); i++){
            dp[i+1] =  max(nums[i], dp[i]+nums[i]);
            rst = max(dp[i+1], rst);
        }
        return rst;
*/
















    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int ret = INT_MIN;
        int tmp = 0;
        for(int i = 0; i < n; i++){
            tmp = max(nums[i], tmp+nums[i]);
            ret = max(tmp, ret);
        }
        return ret;
    }
};