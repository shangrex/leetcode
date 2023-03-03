class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1, mid;
        while(left <= right){
            mid = (left+right)/2;
            if(nums[mid] == target)return mid;
            if(left==right)break;
            // right is sorted
            if(nums[mid] < nums[right]){
                // target in right
                if(nums[mid] < target && target <= nums[right]){
                    left = mid + 1;
                }
                // target in left
                else {
                    right = mid;
                }
            }
            // left is sorted
            else {
                // target in left
                if(nums[left] <= target && target < nums[mid]){
                    right = mid;
                }
                // target in right
                else {
                    left = mid+1;
                }
            }
        }
        // not found
        return -1;
    }
};