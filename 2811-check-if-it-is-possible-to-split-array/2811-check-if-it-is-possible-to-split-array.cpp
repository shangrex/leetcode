class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        if(nums.size() < 3)return true;
        int cnt = nums[0];
        for(int i = 1; i < nums.size(); i++){
            cnt += nums[i];
            if(cnt >= m)return true;
            cnt -= nums[i-1];
        }
        return false;
    }
};