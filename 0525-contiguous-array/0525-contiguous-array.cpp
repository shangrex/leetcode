class Solution {
public:
    /*
    approach 1: bruce force
    approach 2: DP
    time: O(N)
    space: O(N^2)
    
    approach 3: store the count value
    time: O(N)
    space: O(N^2)
    */
    int findMaxLength(vector<int>& nums) {
        vector<int> arr_value(nums.size()*2+2, 100001); 
        int count = 0, max_length = 0;
        arr_value[nums.size()+1] = -1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0)count-=1;
            else count+=1;
            if(arr_value[count+nums.size()+1] != 100001){
                max_length = max(max_length, i - arr_value[count+nums.size()+1]);
            }
            else {
                arr_value[count+nums.size()+1] = i;
            }
        }
        return max_length;
    }
};