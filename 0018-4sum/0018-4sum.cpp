class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        set<vector<int>>s;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n-2; j++){
                long long f = (long long)target - (long long)nums[i] - (long long)nums[j];

                int low = j+1, high = n -1;
                while(low < high){
                    if(nums[low] + nums[high] > f){
                        high--;
                    }
                    else if(nums[low] + nums[high] < f){
                        low++;
                    }
                    else {
                        s.insert({nums[i], nums[j], nums[low], nums[high]});
                        low++;
                    }
                }
            }
        }

        for(auto &it : s){
            ret.push_back(it);
        }
        return ret;
    }
};