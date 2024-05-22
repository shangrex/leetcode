class Solution {
public:
    /*
    Approach 1. Guass 
    Approach 2. XOR with iterator
    */
    int missingNumber(vector<int>& nums) {
        int rst = 0;
        for(int i = 0; i < nums.size(); i++){
            rst ^= i;
            rst ^= nums[i];
        }
        rst ^= nums.size();
        return rst;
    }
};