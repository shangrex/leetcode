class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int, int> table;
        int operation = 0;
        for(int i = 0; i < nums.size(); i++){
            // check k-nums[i] exist
            if(table.find(nums[i]) != table.end()) {
                // if exist then operation + 1
                if(table[nums[i]] > 0){
                    operation += 1;
                    table[nums[i]] -= 1;
                }
                else {
                    table[k-nums[i]] += 1;
                }
            }
            // else add new element to table
            else table[k-nums[i]] += 1;
        }
        return operation;
    }
};