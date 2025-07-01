class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ret = INT_MAX;
        int left = 0, right = 0;
        int n = nums.size();

        int tmpSum = 0;
        while(right < n){
            tmpSum += nums[right];
            while(tmpSum >= target){
                ret = min(ret, right-left+1);
                tmpSum -= nums[left];
                left++;
            }
            right++;
        }

        return ret == INT_MAX ? 0 : ret;
    }
};