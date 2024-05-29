class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = 1;
        for(int i = 0; i < nums.size(); i++){
            if(reach < i+1)break;
            reach = max(reach , nums[i]+i+1);
            // cout << reach << endl;
        }
        return reach >= nums.size() ? true : false;
    }
};