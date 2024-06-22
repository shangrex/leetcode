class Solution {
public:
        /*
    To solve interger overflow problem
    1. use double or other bigger range type
    2. control the temp_max and temp temp_min range
    */
    int maxProduct(vector<int>& nums) {
        vector<__int128_t>dp_max(nums.size()+10, 0);
        vector<__int128_t>dp_min(nums.size()+10, 0);
        
        dp_max[0] = 1;
        dp_min[0] = 1;
        for(int i = 1; i <= nums.size(); i++){
            dp_max[i] = max({dp_max[i-1]* nums[i-1],(__int128_t) nums[i-1], dp_min[i-1]* nums[i-1]});
            dp_min[i] = min({(__int128_t) nums[i-1],(__int128_t) dp_min[i-1]*nums[i-1], dp_max[i-1] * nums[i-1]});
        }
        __int128_t  rst = nums[0];
        for(int i = 1; i <= nums.size();i++){
            rst = max(rst, dp_max[i]);
        }
        return rst;
    }
};