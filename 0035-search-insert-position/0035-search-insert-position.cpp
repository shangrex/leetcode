class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int leftIdx = 0, rightIdx = nums.size();

        while(leftIdx < rightIdx){
            int mid = (leftIdx + rightIdx) / 2;
            if(target == nums[mid]){
                return mid;
            }
            else if(target > nums[mid]){
                leftIdx = mid+1;
            }
            else rightIdx = mid;
        }
        return leftIdx;
    }
};