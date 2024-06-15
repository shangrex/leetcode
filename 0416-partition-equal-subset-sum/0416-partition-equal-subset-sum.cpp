class Solution {
public:
    
    bool sub(vector<vector<int>>&memo, vector<int>&nums, int index, int cnt, int &half_sum){
        if(cnt == half_sum){
            cout << cnt  << " " << half_sum << endl;
            return true;
        }
        else if(index == nums.size() || cnt > half_sum){
            cout << cnt  << " " << half_sum << endl;
            return false;
        }
        if(memo[index][cnt] != -1)return memo[index][cnt];
        bool check = false;        
        cnt += nums[index];
        check |= sub(memo, nums, index+1, cnt, half_sum);
        cnt -= nums[index];
        check |= sub(memo, nums, index+1, cnt, half_sum);
        memo[index][cnt] = check;
        return check;
        
    }
    
    bool canPartition(vector<int>& nums) {
        int half_sum = 0;
        for(auto &num : nums){
            half_sum += num;
        }
        if(half_sum % 2)return false;
        else half_sum /= 2;
        vector<vector<int>>memo(nums.size()+1, vector<int>(half_sum+2, -1));
        return sub(memo, nums, 0,0, half_sum);
        
    }
};