class Solution {
public:
    bool search(vector<int>& nums, int target) {
        /*
        remember 
        if(nums[mid] == nums[leftIdx]){
            leftIdx++;
            continue;
        }
        */
        int leftIdx = 0, rightIdx = nums.size();
        // 5
        while(leftIdx < rightIdx){
            int mid = (leftIdx + rightIdx) / 2;
            // mid 2
            // mid 3
            cout << leftIdx << " " << rightIdx << endl;
            if(mid != leftIdx && nums[mid] == nums[leftIdx]){
                leftIdx++;
                // left 1
                continue;
            }
            // mid 2
            // 3
            if(nums[mid] == target) return true;
            else if(nums[leftIdx] < nums[mid]){
                // left is in increasing order
                if(nums[mid] > target && nums[leftIdx] <= target){
                    rightIdx = mid;
                }
                else {
                    // r = 3
                    leftIdx = mid + 1;
                }
            }
            else {
               // right is in increasing order
                if(nums[mid] < target && nums[nums.size()-1] >= target){
                    leftIdx = mid + 1;
                }
                else {
                    rightIdx = mid;
                }
            }
        }
        return false;
    }
};