class Solution {
public:
    
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
};