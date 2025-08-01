class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ret = 0;
        for(auto &n : nums){
            ret ^= n;
        }
        return ret;
    }
};