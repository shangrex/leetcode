class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum_num = (nums.size()+1)*nums.size()/2, tmp=0;
        for(int i = 0; i < nums.size(); i++){
            tmp += nums[i];
        }
        return sum_num - tmp;
    }
};