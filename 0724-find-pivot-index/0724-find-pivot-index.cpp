class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int tot = 0, leftSum = 0;
        for(auto &num : nums){
            tot += num;
        }

        for(int i = 0; i < nums.size(); i++){
            if((tot-nums[i]) % 2 == 0 && (tot-nums[i])/2 == leftSum) return i;
            leftSum += nums[i];
        }
        return -1;
    }
};