class Solution {
    // method 1 summarization
    /*
        int missingNumber(vector<int>& nums) {
        int n = nums.size(), sum_num, tmp=0;
        sum_num = (n*n+n)/2;
        for(int i = 0; i < nums.size(); i++){
            tmp += nums[i];
        }
        return sum_num - tmp;
    }
    */
    // method 2 xor
public:
    int missingNumber(vector<int>& nums) {
        int tmp = 0;
        for(int i = 0; i < nums.size(); i++){
            tmp ^= i;
            tmp ^= nums[i];
        }
        tmp ^= nums.size();
        return tmp;
    }
};