class Solution {
public:
    int helper(vector<int>nums, int l, int r){
        // pre means l-2 maximun, cur means l-1 maxixmum
        int pre = 0, cur = 0, tmp;
        for(int i = l; i <= r; i++){
            tmp = max(pre+nums[i], cur);
            pre = cur;
            cur = tmp;
        }
        return cur;
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        return max(helper(nums, 0, nums.size()-2), helper(nums, 1, nums.size()-1));
    }
};