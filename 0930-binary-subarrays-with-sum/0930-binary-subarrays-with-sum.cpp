class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        /*
        Approach 1. sliding window
        atMost - atMost

        Approach 2. prefix sum

        */

        unordered_map<int, int> mp;
        
        long long prefix = 0;
        int ret = 0;
        for(int i = 1; i <= nums.size(); i++){
            prefix += nums[i-1];
            if(prefix == goal) ret++;

            if(mp.find(prefix - goal) != mp.end()){
                ret += mp[prefix - goal];
            }
            mp[prefix]++;
        }
        return ret;
        // return atMost(nums, goal) - atMost(nums, goal-1);
    }

    int atMost(vector<int> &nums, int goal){
        int left = 0, right = 0;
        long long tmpSum = 0;
        int ret = 0;
        while(right < nums.size()){
            tmpSum += nums[right];
            while(left <= right && tmpSum > goal){
                tmpSum -= nums[left];
                left++;
            }
            ret += right - left +1;
            right++;
        }
        //cout << ret << endl;
        return ret;
    }
};