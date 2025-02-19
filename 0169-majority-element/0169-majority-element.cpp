class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int>mp;
        for(auto num:nums){
            mp[num] += 1;
            if(mp[num] > n/2) return num;
        }
        return -1;
    }
};