class Solution {
public:
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
};