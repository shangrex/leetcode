class Solution {
public:
    /*
    approach 1. unoredred_map
    */
    int majorityElement(vector<int>& nums) {
        map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]] += 1;
            if(mp[nums[i]] > nums.size()/2)return nums[i];
        }
        
        return 0;
    }
};