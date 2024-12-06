class Solution {
public:
    /*
    Appraoch 1. bottom up DP
    dp[i] store the step from 0
    transition: dp[i+j] = min(dp[i+j], 1+dp[i])
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

    Appraoch 2. top down DP
    transition : dp[pos] = min(dp[pos], )
    */

    // int solve(vector<int>&nums, vector<int>&dp, int pos){
    //     if(pos >= nums.size()-1) return 0;

    //     if(dp[pos] != 101010) return dp[pos];

    //     for(int i = 1; i <= nums[pos]; i++){
    //         if(pos+i < nums.size())
    //             dp[pos] = min(dp[pos], 1+solve(nums, dp, pos+i));
    //     }
    //     return dp[pos];
    // }

    void solve(vector<int>&nums, vector<int>&dp, int idx){
        int n = nums.size();
        if(idx >= n) return;
        cout << idx << endl;
        for(int i = 1; i <= nums[idx]; i++){
            if(idx+i >= n) return;
            dp[idx+i] = min(dp[idx+i], dp[idx]+1);
        }
        solve(nums, dp, idx+1);
    }

    int jump(vector<int>& nums) {
        // int n = nums.size();
        // vector<int>dp(n, 101010);
        // return solve(nums, dp, 0);
        int n = nums.size();
        vector<int>dp(n, 101010101);
        dp[0] = 0;
        solve(nums, dp, 0);
        return dp[n-1];
    }
};