class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int>left, count, freq;
        
        for(int i = 0; i < nums.size(); i++){
            if(left.find(nums[i]) == left.end()){left[nums[i]] = i;count[nums[i]] = 1;}
            else count[nums[i]] = i-left[nums[i]]+1;
            if(freq.find(nums[i]) != freq.end())freq[nums[i]]++;
            else freq[nums[i]] = 1;
        }
        
        int max_freq = 0;
        
        for(auto i : freq)max_freq = max(max_freq, i.second);
        
        // cout << max_freq << endl;
        
        int rst = INT_MAX;
        for(auto i : freq){
            if(i.second == max_freq){
                // cout << i.first;
                rst = min(rst, count[i.first]);
            }
        }
        
        
        return rst;
        
        
        
        
    }
};