class Solution {
public:
    /*
    Approach 1. use an array to record
        int n = nums.size();
        vector<bool> seen(n+2, false);

        for(auto & num : nums){
            if(num > 0 && num <= n){
                seen[num] = true;
            }
        }

        for(int i = 1; i <= n+1; i++){
            if(!seen[i]) return i;
        }
        return -1;
    Approach 2. cycle sort

    */
    int firstMissingPositive(vector<int>& nums) {
        /*
        [1, 2, 0]

        */
        int n = nums.size();
        int i = 0;
        while(i < n){
            if(nums[i] > 0 && nums[i] < n && nums[i] != i+1){
                if(nums[i] == nums[nums[i]-1]) {i++; continue;} 
                swap(nums[i], nums[nums[i]-1]);
            }
            else i++;
        }
        for(int i = 0; i < n;i++){
            if(nums[i] != i+1){
                return i+1;
            }
        }
        return n+1;
    }
};