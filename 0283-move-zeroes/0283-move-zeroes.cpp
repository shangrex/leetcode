class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                swap(nums[i], nums[left++]);
            }
        }
    }
};