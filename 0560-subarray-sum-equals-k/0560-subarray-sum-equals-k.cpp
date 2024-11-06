class Solution {
public:
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