class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        if(nums.size() == 0)return nums;
        vector<int>rst(nums.size(), 0);
        int right = nums.size()-1, left = 0, fill = nums.size()-1;
        while(left <= right){
            if(nums[right]*nums[right] < nums[left]*nums[left]){
                rst[fill] = nums[left]*nums[left];
                fill--;
                left++;
            }
            else {
                rst[fill] = nums[right]*nums[right];
                fill--;
                right--;
            }
        }
        return rst;
    }
};