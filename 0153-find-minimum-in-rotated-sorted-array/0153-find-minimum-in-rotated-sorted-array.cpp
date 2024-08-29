class Solution {
public:
    /*
    Hint: Find the inflection point (that the turning point of the sorted array)
    */
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        while(left < right){
            int mid = (left+right) /2;
            
            if(nums[left] < nums[right]){
                return nums[left];
            }
            
            if(nums[mid] > nums[right]){
                // left is ascending
                left = mid+1;
            }
            else if(nums[mid] < nums[right]){
                // right is ascending
                right = mid;
            }
        }
        return nums[left];
    }
};