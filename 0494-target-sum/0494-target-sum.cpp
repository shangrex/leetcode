/* backtrack
    void backtrack(vector<int>&nums, int idx, int sum, vector<int>&ans, int& target ){
        if(idx >= nums.size()){
            // cout << sum << endl;
            ans.push_back(sum);
            return;
        }
        
        backtrack(nums, idx+1, sum+nums[idx], ans, target);
        backtrack(nums, idx+1, sum-nums[idx], ans, target);

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<int> ans;
        backtrack(nums, 0, 0, ans, target);
        int rst = 0;
        for(auto i : ans){
            if(i == target){
                rst++;
            }
        }
        return rst;
    }
*/
class Solution {
public:
    /*
    Approach 1.backtrack
    Appraoch 2.memo 
    */
    int rst = 0;
    int backtrack(vector<int>&nums, int idx, int sum, int& target, vector<vector<int>> &memo){
        if(idx >= nums.size()){
            // cout << sum << endl;
            if(target == sum)return 1;
            return 0;
        }
        //cout << idx<< " " << sum+nums[idx] << endl;
        
        if(memo[idx][sum+5000] != INT_MIN) return memo[idx][sum+5000];
        int a = backtrack(nums, idx+1, sum+nums[idx], target, memo);
        int b = backtrack(nums, idx+1, sum-nums[idx], target, memo);
        memo[idx][sum+5000] = a+b;
        return memo[idx][sum+5000];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<int> ans;
        vector<vector<int>> memo(nums.size(), vector<int>(1010000, INT_MIN));
        return backtrack(nums, 0, 0, target, memo);
    }
};