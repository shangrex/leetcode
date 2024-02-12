class Solution {
public:
    /*
        method 1. to optimize the find function in backtrack, we need to use another vector used to store whether already in pool or not.
        draw the selection from the pool
        method 2.
        swap the number in nums
    */
    void backtrack(vector<int>&nums, vector<int>&pool, vector<bool>&used, vector<vector<int>>& rst){

        if(pool.size() == nums.size()){
            rst.push_back(pool);
            return;
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(used[i] == false){
                used[i] = true;
                pool.push_back(nums[i]);
                backtrack(nums, pool, used, rst);
                pool.pop_back();
                used[i] = false;
            }
        }
        return;
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> rst;
        vector<int>pool;
        vector<bool>used(nums.size(), false);
        backtrack(nums, pool, used, rst);
        return rst;
    }
};