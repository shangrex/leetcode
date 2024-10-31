class Solution {
public:
    int jump(vector<int>& nums) {
        int boarder = 0;
        int rst = 0;
        int n = nums.size();
        int total = 1000;
        vector<int>dp(n, INT_MAX);
        
        dp[0] = 0;
        for(int i = 0; i < n; i++){
            for(int j = 1; j <= nums[i]; j++){
                if(i+j < n){
                    dp[i+j] = min(dp[i]+1, dp[i+j]);
                }
            }
        }
        return dp[n-1];
    }
};