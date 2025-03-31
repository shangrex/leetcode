class Solution {
public:

    vector<int> nums;
    Solution(vector<int>& nums) {
        this->nums.swap(nums);
    }
    
    int pick(int target) {
        int n = nums.size();
        int cnt = 0;
        int idx = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] == target){
                cnt++;

                if(rand() % cnt == 0){
                    idx = i;
                }
            }
        }

        return idx;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */