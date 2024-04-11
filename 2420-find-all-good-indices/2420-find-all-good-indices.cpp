class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        vector<int>decrease(nums.size()+1, 1);
        vector<int>increase(nums.size()+1, 1);
        
        
//         decrease[0]=1;
//         increase[0]=1;
        for(int i = 1; i < nums.size()-1; i++){
            if(nums[i] <= nums[i-1]){
                decrease[i] = 1+decrease[i-1];
            }
        }
        
        for(int i = nums.size()-2; i > 0; i--){
            if(nums[i] <= nums[i+1]){
                increase[i] = increase[i+1]+1;
            }
        }
        
        vector<int>rst;
        for(int i = 1; i < nums.size()-1; i++){
            if(decrease[i-1] >= k && increase[i+1] >=k){
                rst.push_back(i);
            }
        }
        return rst;
    }
};