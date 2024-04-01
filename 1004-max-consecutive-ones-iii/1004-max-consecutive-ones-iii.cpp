class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int numzeros = 0;
        int longests = 0;
        
        while(right < nums.size()){
            if(nums[right] == 0){
                numzeros++;
            }
            
            while(numzeros == k+1){
                if(nums[left] == 0){
                    numzeros--;
                }
                left++;
            }
            
            longests = max(longests, right - left + 1);
            right++;
        }
        
        return longests;
    }
};