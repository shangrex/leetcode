class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int tot = 0;
        unordered_map<int, int>mp;
        for(auto &num : nums){
            tot += num;
            mp[num]++;
        }
        int rst = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            int tmp_tot = tot - nums[i];
            mp[nums[i]]--;
            if(tmp_tot % 2 == 0 && mp[tmp_tot/2] > 0){
                rst = max(rst, nums[i]);
            }
            mp[nums[i]]++;

        }

        return rst;
    }
};