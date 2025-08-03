class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0, right = nums.size()-1, fill = nums.size()-1;
        vector<int>ret(nums.size(), 0);
        while(left <= right){
            if(nums[left]*nums[left] < nums[right]*nums[right] ){
                ret[fill] = nums[right]*nums[right];
                right--;
                fill--;
            }
            else {
                ret[fill] = nums[left]*nums[left];
                left++;
                fill--;
            }
        }
        return ret;
    }
};