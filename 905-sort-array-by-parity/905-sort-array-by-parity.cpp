class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0, j = 0;
        // two pointer
        // i go through odd
        // j go through even
        while(i < nums.size() && j < nums.size()){
            // find even
            while(nums[i] % 2 == 1){
                i++;
                if(i >= nums.size())break;
            }
            // find the first odd
            while(nums[j] % 2 == 0){
                j++;
                if(j >= nums.size())break;
            }
            if(i >= nums.size())break;
            if(j >= nums.size())break;
            if(i > j){
                swap(nums[i], nums[j]);
                j++;
            }
            else {
                i++;
            }
        }
        return nums;
    }
};