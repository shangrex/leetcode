class Solution {
public:
    void backtrack(vector<int>&nums, int index, vector<vector<int>>&rst, vector<int>&pool){
        if(index > nums.size())return;
        
        rst.push_back(pool);
        
        for(int i = index; i < nums.size(); i++){
            pool.push_back(nums[i]);
            backtrack(nums, i+1, rst, pool);
            pool.pop_back();
        }

        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>rst;
        vector<int>pool;
        backtrack(nums, 0, rst, pool);
        return rst;
    }
};