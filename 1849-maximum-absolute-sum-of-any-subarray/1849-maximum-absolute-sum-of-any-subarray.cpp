class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
         int ret = 0;
         int max_ret = INT_MIN;
         int min_ret = INT_MAX;
         int n = nums.size();
        
        int max_tmp = 0;
        int min_tmp = 0;
        for(int i = 0; i < n; i++){
            max_tmp = max(nums[i], max_tmp + nums[i]);
            max_ret = max(max_tmp, max_ret);

            min_tmp = min(nums[i], min_tmp + nums[i]);
            min_ret = min(min_tmp, min_ret);
        }

        return max(abs(min_ret), max_ret);
    }
};