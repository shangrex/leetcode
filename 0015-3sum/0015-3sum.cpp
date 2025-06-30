class Solution {
public:
    /*
    Changed the problems to three sum

    Approah 1. two pointer
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
    */

    void twoSum(vector<int> &nums, int i, vector<vector<int>> &ret){
        unordered_map<int, int>mp;
        int target = -nums[i];
        for(int j = i+1; j < nums.size();j++){
            if(mp.find(target - nums[j]) != mp.end()){
                cout << nums[i] << " " << nums[j] << endl;
                ret.push_back({nums[i], nums[j], -nums[i]-nums[j]});
                mp[nums[j]]++;
                while(j < nums.size()-1 && nums[j] == nums[j+1] )j++;
            }
            else {mp[nums[j]]++;}
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ret;
        for(int i = 0; i < nums.size(); i++){
            if(i == 0 || nums[i] != nums[i-1]){
                twoSum(nums, i, ret);
            }
        }

        return ret;
    }
};