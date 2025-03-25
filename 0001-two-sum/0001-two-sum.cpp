class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // sort(nums.begin(), nums.end());
        // int left = 0, right = nums.size()-1;
        // while(left < right){
        //     if(nums[left]+nums[right] == target) return {left, right};
        //     else if(nums[left] + nums[right] > target){
        //         right--;
        //     }
        //     else left++;
        // }
        // return {};

        unordered_map<int, int>mp;
        for(int i = 0; i < nums.size(); i++){
            if(mp.find(target-nums[i]) != mp.end()) return {i, mp[target-nums[i]]};
            mp[nums[i]] = i;
            
        }
        return {};
    }
};