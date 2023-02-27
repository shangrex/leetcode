class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // be careful division zero
        vector<int>ans(nums.size(), 1);
        long long int suffix = 1;
        // prefix 
        for(int i = 1; i < nums.size(); i++){
            ans[i] = nums[i-1]*ans[i-1];
        }
        // suffix
        for(int i = nums.size()-1; i > 0; i--){
            suffix = suffix*nums[i];
            ans[i-1] = ans[i-1]*suffix;
        }
        return ans;
    }
};