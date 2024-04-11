class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int>left, right, freq;
        
        for(int i = 0; i < nums.size(); i++){
            if(left.find(nums[i]) == left.end()){left[nums[i]] = i;}
            // else count[nums[i]] = i-left[nums[i]]+1;
            right[nums[i]] = i;
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
                rst = min(rst, right[i.first] - left[i.first] + 1);
            }
        }
        
        
        return rst;
        
        
        
        
    }
};