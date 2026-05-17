class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ret = 0;
        int left = 0, right = 0;
        unordered_map<int, int> mp;
        long long tmpSum = 0;
        while(right < nums.size()){
            mp[nums[right]]++;
            tmpSum += nums[right];

            while(mp[nums[right]] > 1 || right - left+1 > k){
                // duplicate
                mp[nums[left]]--;
                tmpSum -= nums[left];
                if(mp[nums[left]] == 0){
                    mp.erase(nums[left]);
                }
                left++;
            }
            if(right - left + 1 == k)ret = max(ret, tmpSum);
            right++;
        }
        return ret;
    }
};