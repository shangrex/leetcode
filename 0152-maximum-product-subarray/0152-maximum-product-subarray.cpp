class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int rst = -10, tmp_min = -10, tmp_max = 10;
        int tmp;
        tmp_min = rst = tmp_max = nums[0];
        for(int i = 1;i < nums.size(); i++){
            tmp = max({nums[i], nums[i]*tmp_max, nums[i]*tmp_min});
            rst = max(rst, tmp);
            // max subarray value
            tmp = max({1, tmp_max*nums[i], nums[i], tmp_min*nums[i]});
            // min subarray value
            tmp_min = min({tmp_min*nums[i], nums[i], tmp_max*nums[i]});
            tmp_max = tmp;
        }
        return rst;
    }
};