class Solution {
public:
    void backtrack(int index, vector<int>&nums, vector<int>&pool, vector<vector<int>>&rst){
        rst.push_back(pool);
        for(int i = index; i < nums.size(); i++){
            pool.push_back(nums[i]);
            backtrack(i+1, nums, pool, rst);
            pool.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>rst;
        vector<int>pool;
        
        backtrack(0, nums, pool, rst);
        return rst;
    }
};