class Solution {
public:
    /*tmp
    unordered_map<int, int>mp;
        for(int i = 0; i < nums.size(); i++){
            int diff = target-nums[i];
            // exist
            if(mp.find(diff) != mp.end()){
                return {i, mp[diff]};
            }
            mp[nums[i]] = i;
        }
        return {};
    */
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>mp;
        for(int i = 0; i < nums.size(); i++){
            if( mp.find( target-nums[i] ) == mp.end()){
                // not exist
                mp[nums[i]] = i;
            }
            else return {i, mp[target-nums[i]]};
        }

        return {};
    };
};