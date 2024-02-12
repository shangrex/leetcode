class Solution {
public:
    
    
    void backtrack(vector<int>&nums, vector<int>&pool, vector<vector<int>>& rst){

        if(pool.size() == nums.size()){
            rst.push_back(pool);
            return;
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(find(pool.begin(), pool.end(), nums[i]) == pool.end()){
                pool.push_back(nums[i]);
                backtrack(nums, pool, rst);
                pool.pop_back();
            }
        }
        return;
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> rst;
        vector<int>pool;
        backtrack(nums, pool, rst);
        return rst;
    }
};