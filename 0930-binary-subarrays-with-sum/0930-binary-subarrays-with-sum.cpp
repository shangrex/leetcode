class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal-1);
    }

    int atMost(vector<int> &nums, int goal){
        int left = 0, right = 0;
        long long tmpSum = 0;
        int ret = 0;
        while(right < nums.size()){
            tmpSum += nums[right];
            while(left <= right && tmpSum > goal){
                tmpSum -= nums[left];
                left++;
            }
            ret += right - left +1;
            right++;
        }
        //cout << ret << endl;
        return ret;
    }
};