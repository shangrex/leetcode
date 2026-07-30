class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        /*
        store max int and max negative integer

        Approach 1. sorting
        */

        sort(nums.begin(), nums.end());

        int allPos = 1;
        int n = nums.size();
        for(int i = 0; i < 3; i++){
            if(nums[n-i-1] < 0) {allPos = INT_MIN; break;}
            if(nums[n-i-1] == 0) allPos = 0;
            allPos *= nums[n-i-1];
        }

        int twoNeg = 1;
        for(int i = 0; i < 2; i++){
            twoNeg *= nums[i];
        }
        if(twoNeg > 0) twoNeg *= nums[n-1];
        else twoNeg *= nums[2];
        
        // all negative
        int allNeg = 1;
        for(int i = 0; i < 3; i++){
            allNeg *= nums[n-i-1];
        }

        return max(allNeg, max(twoNeg, allPos));
    }
};