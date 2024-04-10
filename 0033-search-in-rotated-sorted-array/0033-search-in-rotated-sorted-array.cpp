class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        if(nums.size() == 1 && nums[0] == target) return 0;
        int left = 0, right = nums.size();
        
        while(left < right){
            int mid = (left+right)/2;
            // cout << left << ' ' << mid << ' ' << right << endl;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > nums[right-1]){
                // left is asceding
                if(target >= nums[left] && target < nums[mid]){
                    // target is in left split
                    right = mid;
                }
                else {
                    left = mid+1;
                }
            }
            else {
                // right is in asceding
                if(nums[right-1] >= target && nums[mid] < target){
                    // target is in right split
                    left = mid+1;
                }
                else {
                    right = mid;
                }
            }
        }
        return -1;
    }
};