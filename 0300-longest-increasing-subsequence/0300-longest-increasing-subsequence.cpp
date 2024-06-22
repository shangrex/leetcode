class Solution {
public:
    /*
    Approach 1. DP
    dp[i] = max(dp[i], dp[0~i-1]+1)
    
        int lengthOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size()+1, 1);
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        
        int rst = 0;
        for(int i = 0; i < nums.size(); i++){
            rst = max(rst, dp[i]);
        }
        return rst;
    }
    
    Approach 2. Use a sub array to maintain the optimze sub array
    [0, 2 ,3, 10] -> insert 5 [0, 2, 5, 10]
    
    */
    int lengthOfLIS(vector<int>& nums) {
        vector<int>sub;
        sub.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > sub.back()){
                sub.push_back(nums[i]);
            }
            else {
                int j = 0;
                while(sub[j] < nums[i]){
                    j++;
                }
                sub[j] = nums[i];
            }
        }
        int n = sub.size();
        return n;
    }
};