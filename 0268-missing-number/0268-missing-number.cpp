class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), sum_num, tmp=0;
        sum_num = (n*n+n)/2;
        for(int i = 0; i < nums.size(); i++){
            tmp += nums[i];
        }
        return sum_num - tmp;
    }
};