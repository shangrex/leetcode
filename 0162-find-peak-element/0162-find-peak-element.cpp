class Solution {
public:
    /*
    1. bructe force

    2. binary search
    ending condition 
    and the left right movement condition

    */

    int findPeak(vector<int>&nums, int left, int right){
        if(left >= right) return left;
        // 1 2 3 4 3
        // 0 1 2 3 4
        //.    l   r
        //       m
        //     m r
        // 1 2 3 1
        //.  m
        // l l   r
        //     m
        //.    
        // [1,2]
        //  0 1
        //  l r
        //. m 

        int mid_idx = (left+right)/2;

        if(nums[mid_idx] > nums[mid_idx+1]){
            right = mid_idx;
        }
        else {
            left = mid_idx+1;
        }
        return findPeak(nums, left, right);
    }
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        // return findPeak(nums, left, right);

        while(left < right){
            int mid = (left+right)/2;
            if(nums[mid] > nums[mid+1]){
                right = mid;
            }
            else left = mid+1;
        }

        return left;
    }
};