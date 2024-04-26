class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int rst = 0;
        long long product = 1;
        while(right < nums.size()){
            product *= nums[right++];
        
            while(product >= k && left < nums.size() && left < right){
                product /= nums[left];
                left++;
            }
            rst += (right-left);
        }
        return rst;
    }
};