class Solution {
public:
  
    void backtrack(vector<vector<int>> &ret, vector<int>&nums, vector<int>tmp, int idx){
        if(idx >= nums.size()){
            ret.push_back(tmp);
            return;
        }
        backtrack(ret, nums, tmp, idx+1);
        tmp.push_back(nums[idx]);
        backtrack(ret, nums, tmp, idx+1);
        tmp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> tmp;
        int idx = 0;
        backtrack(ret, nums, tmp, idx);
        return ret;
    }
    

    // void backtrack(int idx, vector<vector<int>>&rst, vector<int>&nums, vector<int>&pool){
    //     if(idx == nums.size())rst.push_back(pool);
    //     for(int i = idx; i < nums.size(); i++){
    //         pool.push_back(nums[i]);
    //         backtrack(idx+1, rst, nums, pool);
    //         pool.pop_back();
    //         backtrack(idx+1, rst, nums, pool);
    //     }
    // }
    // vector<vector<int>> subsets(vector<int>& nums) {
    //     vector<vector<int>> rst;
    //     vector<int>pool;
    //     backtrack(0, rst, nums, pool);
    //     return rst;
    // }
};