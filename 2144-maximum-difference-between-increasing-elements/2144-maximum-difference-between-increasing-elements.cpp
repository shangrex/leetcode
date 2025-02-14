class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int min_num = nums[0];
        int ret = -1;
        for(int i = 1; i < nums.size(); i++){
            min_num = min(min_num, nums[i]);
            if(nums[i] > min_num)
                ret = max(ret, nums[i] - min_num);
        }
        return ret;
    }
};