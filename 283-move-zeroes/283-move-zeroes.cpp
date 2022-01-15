class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int read = 0, write = 0;
        for(; read < nums.size(); read++){
            if(nums[read] != 0){
                nums[write] = nums[read];
                write++;
            }
        }
        for(;write < nums.size(); write++){
            nums[write] = 0;
        }
    }
};