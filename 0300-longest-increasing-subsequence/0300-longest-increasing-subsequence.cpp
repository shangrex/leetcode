class Solution {
// method 1 dp 
/*
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
    }*/
// greedy with binary search
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0)return 0;
        vector<int>dp;
        dp.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++){
            if(dp.back() < nums[i])dp.push_back(nums[i]);
            else if(dp.back()==nums[i])continue;
            else {
                // binary search and insert
                int l = 0, r = dp.size()-1;
                while(l<r){
                    int mid = (l+r)/2;
                    if(dp[mid]<nums[i])l=mid+1;
                    else r=mid;
                }
                dp[l] = nums[i];
            }
        }
        return dp.size();
    }
};