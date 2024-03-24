class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int cnt = 0;
        int product_sum = 1;
        
        for(int i = 0, j = 0; j < nums.size(); j++){
            product_sum *= nums[j];
            while(product_sum >= k && i <= j){
                product_sum /= nums[i++];
            }
            cnt += (j - i + 1);
        }
        
        return cnt;
    }
};