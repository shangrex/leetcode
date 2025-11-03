class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int ret = 0;
        long sumArray = 0;
        for(int i = 0; i < nums.size(); i++){
            sumArray += nums[i];
        }

        long prefix = 0;
        for(int i = 0; i < nums.size()-1; i++){
            prefix += nums[i];
            if(prefix >= sumArray - prefix){
                ret+=1;
            }
        }

        return ret;
    }
};