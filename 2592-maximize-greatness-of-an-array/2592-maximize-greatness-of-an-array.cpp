class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        /*
        1 2 3 4 5
        2 3 4 5 1

        1 1 2 3 4 5
        2 3 4 5 1 1

        1 1 2 2 3
        2 2 3 1 1 ->3 -> 5 - 1 - 1 

        1 1 1 2 3 3 5
        2 3 3 5 1 1 1
        Approach 1.
        sort, then binary search
        */

        int ret = 0;
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int t = -1;
        int bigger = 0;
        for(int i = 0; i < nums.size() || bigger < nums.size(); i++){
            while(bigger < nums.size() && i < nums.size() && nums[bigger] <= nums[i]){
                bigger++;
            }
        
            if(bigger < nums.size()) {ret++; bigger++;}
        }

        return ret;
    }
};