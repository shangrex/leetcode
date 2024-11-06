class Solution {
public:
/*
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
*/
    int subarraySum(vector<int>& nums, int k) {
        vector<long long> prefix;
        long long cum = 0;
        for(int i = 0; i < nums.size(); i++){
            cum += nums[i];
            prefix.push_back(cum);
        }
        int rst = 0;
        for(int i = 0; i < nums.size(); i++){
            if(prefix[i] == k) rst++;
            for(int j = 0; j < i; j++){
                if(prefix[i] - prefix[j] == k)rst++;
            }
        }
        return rst;
    }
};