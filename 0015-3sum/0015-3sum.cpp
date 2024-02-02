class Solution {
public:
    /*
        vector< vector<int>> rst;
        int target;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-1;){
            int l = i+1, r = nums.size()-1;
            target = -nums[i];
            while(l < r){
                if(nums[l]+nums[r] == target){
                    rst.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    while(nums[l] == nums[l-1] && l<r){l++;}
                }
                while(nums[l]+nums[r]>target && l<r)r--;
                while(nums[l]+nums[r]<target && l<r)l++;
            }
            i++;
            while(nums[i] == nums[i-1] && i < nums.size()-2)i++;
        }
        return rst;
    */
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> rst;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size(); i++){
            while(i>0 && i < nums.size()-2 && nums[i] == nums[i-1])i++;
            int l = i+1, r = nums.size()-1;

            while(l < r){
                if(nums[i] + nums[l] + nums[r] > 0){
                    r--;
                    while(l<r && nums[r] == nums[r+1])r--;
                }
                else if(nums[i] + nums[l] + nums[r] < 0){
                    l++;
                    while(l<r && nums[l] == nums[l-1])l++;
                }
                else {
                    rst.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    while(l<r && nums[l] == nums[l-1])l++;
                }
            }
        }
        
        return rst;
    }
};