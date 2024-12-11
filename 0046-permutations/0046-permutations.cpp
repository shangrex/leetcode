class Solution {
public:
    // 1 2 3
    // 1 3 2
    // 2 1 3
    // 2 3 1
    void backtrack(vector<int>&nums, vector<vector<int>>&rst, set<int>&pool, vector<int>&bag){
        if(bag.size() == nums.size()){
            rst.push_back(bag);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(pool.count(nums[i]) == 0){
                bag.push_back(nums[i]);
                pool.insert(nums[i]);
                backtrack(nums, rst, pool, bag);
                bag.pop_back();
                pool.erase(nums[i]);
            }
        }
    } 
    vector<vector<int>> permute(vector<int>& nums) {
        set<int>pool;
        vector<int>bag;
        vector<vector<int>> rst;
        backtrack(nums, rst, pool, bag);
        return rst;
    }
};