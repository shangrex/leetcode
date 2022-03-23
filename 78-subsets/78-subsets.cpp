class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> rst;
        vector<int>tmp;
        rst.push_back(tmp);
        for(int i = 0; i < nums.size(); i++){
            int second = rst.size();
            for(int j = 0; j < second; j++){
                tmp = rst[j];
                tmp.push_back(nums[i]);
                rst.push_back(tmp);
            }
        }
        return rst;
    }
};