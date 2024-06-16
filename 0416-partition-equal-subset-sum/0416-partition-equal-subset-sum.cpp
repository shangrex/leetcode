class Solution {
public:
    /*
    Approach 1. DP top down
    memo[index][subsetsum]
    Approach 2. Bottom up
    dp[index][subsetsum]
    Apprach 3. 1-D DP
    */
    bool sub(vector<vector<int>>&memo, vector<int>&nums, int index, int cnt, int &half_sum){
        if(cnt == half_sum){
            cout << cnt  << " " << half_sum << endl;
            return true;
        }
        else if(index == nums.size() || cnt > half_sum){
            cout << cnt  << " " << half_sum << endl;
            return false;
        }
        if(memo[index][cnt] != -1)return memo[index][cnt];
        bool check = false;        
        check |= sub(memo, nums, index+1, cnt+nums[index], half_sum);
        check |= sub(memo, nums, index+1, cnt, half_sum);
        memo[index][cnt] = check;
        return check;
        
    }
    
    bool canPartition(vector<int>& nums) {
        int half_sum = 0;
        for(auto &num : nums){
            half_sum += num;
        }
        if(half_sum % 2)return false;
        else half_sum /= 2;
        // vector<vector<int>>memo(nums.size()+1, vector<int>(half_sum+2, -1));
        // return sub(memo, nums, 0,0, half_sum);
        vector<vector<bool>>dp(nums.size()+2, vector<bool>(half_sum+2, false));
        
        dp[0][0] = true;
        for(int i = 1; i <= nums.size(); i++){
            for(int j = 0; j <= half_sum; j++){
                if(j >= nums[i-1])
                    dp[i][j] = (dp[i-1][j-nums[i-1]] || dp[i-1][j]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        if(dp[nums.size()][half_sum])return true;
        else return false;
    }
    
};