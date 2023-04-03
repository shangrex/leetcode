class Solution {
public:
    bool canJump(vector<int>& nums) {
        int step = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(step < i)return false;
            step = max(step, nums[i]+i);
        }
        return true;
    }
};