class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int init = nums[0];
        for(int i = 1; i < nums.size(); i++){
            init ^= nums[i];
        }
        return init;
    }
};