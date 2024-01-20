class Solution {
public:
    /*
    unordered_map<int, bool>mp;
        for(int i = 0; i < nums.size(); i ++){
            // not exist
            if(mp.find(nums[i]) == mp.end()){
                mp[nums[i]] = true;
            }
            else return true;
        }
        return false;
    */
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool>mp;
        for(auto i : nums){
            //exist
            if(mp.find(i) != mp.end()){
                return true;
            }
            // not exist
            else mp[i] = true;
        }
        return false;
    }
};