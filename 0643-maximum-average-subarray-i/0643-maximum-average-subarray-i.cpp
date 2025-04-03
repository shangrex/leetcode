class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int tot = 0;
        for(int i = 0; i < k; i++){
            tot += nums[i];
        }
        int max_tot = tot;
        for(int i = 1; i < nums.size()-k+1; i++){
            // 0 1 2 3
            //.   
            tot = tot - nums[i-1] + nums[i+k-1];
            max_tot = max(tot, max_tot);
        }

        return (double)max_tot/(double)k;
    }
};