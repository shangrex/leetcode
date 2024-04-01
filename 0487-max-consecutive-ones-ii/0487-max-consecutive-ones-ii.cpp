class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left = 0, right = 0;
        int numZeroes = 0;
        int longestSequence = 0;
        int k = 1;
        
        while(right < nums.size()){
            if(nums[right] == 0){
                numZeroes++;
            }
            
            while(numZeroes == k+1){
                if(nums[left] == 0){
                    numZeroes --;
                }
                left++;
            }
            
            longestSequence = max(longestSequence, (right - left + 1));
            
            right++;
        }
        return longestSequence;      
    }
};