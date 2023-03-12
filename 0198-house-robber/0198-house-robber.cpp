class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)return nums[0];
        // pre means i-2 maximun, cur means i-1 maxixmum
        int pre = 0, cur = nums[0], tmp;
        for(int i = 1; i < nums.size(); i++){
            tmp = max(pre+nums[i], cur);
            pre = cur;
            cur = tmp;
        }
        return cur;
    }
};