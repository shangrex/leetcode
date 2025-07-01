class Solution {
public:
    /*
    Approach 1. use an array to record
    Approach 2. cycle sort
    */
    int firstMissingPositive(vector<int>& nums) {
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
    }
};