class Solution {
public:
    /*
    Changed the problems to three sum
    */
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>rst;
        for(int i = 0; i < nums.size(); i++){
            while(i > 0 && i < nums.size() && nums[i] == nums[i-1]) i++;
            int left = i+1, right = nums.size()-1;
            while(left < right){
                if(nums[left] + nums[right] > -nums[i]){ right--; while(right >= 0 && nums[right] == nums[right+1])right--;}
                else if(nums[left] + nums[right] < -nums[i]) {left++; while(left < nums.size() && nums[left] == nums[left-1])left++;} 
                else {rst.push_back({nums[i], nums[left], nums[right]}); left++;while(left < nums.size() && nums[left] == nums[left-1])left++;}
            }
        }
        return rst;
    }
};