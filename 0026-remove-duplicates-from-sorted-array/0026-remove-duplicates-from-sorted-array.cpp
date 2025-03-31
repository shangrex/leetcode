class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        // [1, 1, 2]
        //  i.    j
        //.    i
        for(int j = 1; j < nums.size(); j++){
            if(nums[j] != nums[i]){
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;
    }
};