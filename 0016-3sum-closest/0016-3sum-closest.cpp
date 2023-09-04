class Solution {
public:
    /*
    1. sort and use two pointer to find
    */
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int rst = nums[0]+nums[1]+nums[2];
        for(int i = 0; i < nums.size()-2; i++){
            int low = i+1, high = nums.size()-1;
            while(low < high){
                int tmp_sum = nums[low]+nums[high]+nums[i];
                
                if(tmp_sum == target)return tmp_sum;
                
                if(abs(tmp_sum - target) < abs(rst - target)){
                    rst = tmp_sum;
                }
                
                if(tmp_sum < target){
                    low++;
                }
                else {
                    high--;
                }
            }    
        }
        
        return rst;
    }
};