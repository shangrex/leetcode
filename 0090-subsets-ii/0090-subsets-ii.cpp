class Solution {
public:
    
    void backtrack(int index, vector<int>&nums, vector<vector<int>>&rst, vector<int>&pool){
        if(index > nums.size())return;
        // for(auto i:pool)cout << i << " ";
        // cout << endl;
        rst.push_back(pool);
        
        for(int i = index; i < nums.size(); i++){
            if(i != index && nums[i] == nums[i-1]) continue;
            pool.push_back(nums[i]);
            backtrack(i+1, nums, rst, pool);
            pool.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> rst;
        vector<int>pool;
        sort(nums.begin(), nums.end());
        
        backtrack(0, nums, rst, pool);
        
        return rst;
    }
};