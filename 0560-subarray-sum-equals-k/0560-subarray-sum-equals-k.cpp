class Solution {
public:
    /*
    approach 1: cumulative sum
    time: O(N^2)
    space: O(N)
    sum[i] = nums[0]+...+nums[i]
    sum[end] - sum[start] = k
    
    approach 2: 
    */
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0, sum = 0;
        // the frequency of cumulative sum
        unordered_map<int, int>mp;
        mp[0] = 1;
        for(int i = 0;i < nums.size(); i++){
            sum += nums[i];
            if(mp.find(sum-k) != mp.end()){
                ans += mp[sum-k];
            }
            if(mp.find(sum) != mp.end())mp[sum] += 1;
            else mp[sum] = 1;
        }
        return ans;
    }
};