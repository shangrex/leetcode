class Solution {
// thought using recursive to solve binary search
/*
    int find_min(vector<int>nums, int i, int j){
        int mid = nums[(i+j)/2];
        cout << mid << endl;
        if((i+j)/2-i<1)return min(nums[i], nums[j]);
        if(nums[i] < nums[j]) return nums[i];
        else if(nums[i] < mid && mid > nums[j])return find_min(nums, (i+j)/2+1, j);
        else return find_min(nums, i, (i+j)/2);
    }
    int findMin(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        return find_min(nums, 0, nums.size()-1);
    }
*/
// hint -> use while loop to solve binary search
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1, mid;
        while(left < right){
            mid = (left+right)/2;
            // target in right
            if(nums[mid] > nums[right]){
                left = mid+1;
            }
            // target in left
            else if(nums[mid] < nums[right]){
                right = mid;
            }
            else {
                break;
            }
        }
        return nums[left];
    }
};