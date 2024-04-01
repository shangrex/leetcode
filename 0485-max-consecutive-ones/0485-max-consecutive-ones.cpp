class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int rst = 0;
        for(int i = 0; i < nums.size(); i++){            
            int tmp_rst = 0;
            while(i < nums.size() && nums[i] == 1){
                tmp_rst ++;
                i++;
            }
            rst = max(rst, tmp_rst);
        }
        return rst;
    }
};