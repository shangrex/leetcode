class Solution {
public:
    // 1 3 5 6
    // l.  m    r
    //     l  m r
    //          l
    
    // l.  m.   r
    // l.  r
    //   m
    // l r
    // 
    int searchInsert(vector<int>& nums, int target) {
       int left = 0, right = nums.size();
    
        while(left < right){
            int mid = (left+right)/2;
            
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};