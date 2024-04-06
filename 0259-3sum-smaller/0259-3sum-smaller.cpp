class Solution {
public:
    // 1 iterate the first elemt
    // 
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int cnt = 0;
        
        for(int i = 0; i < nums.size(); i++){
            // left right
            int left;
            int right = nums.size()-1;
            for(int j = i+1; j < nums.size() && j < right; j++){
                left = j;
                
                while(left < right){
                    // sum
                    int tmp_sum = nums[i]+nums[left]+nums[right];
                    if(tmp_sum >= target){
                        // move right bounder
                        right--;
                    }
                    else if(tmp_sum < target){
                        // move right bounder
                        break;
                    }
                }     
                cnt += (right-left);
            }

        }
        
        return cnt;
    }
};