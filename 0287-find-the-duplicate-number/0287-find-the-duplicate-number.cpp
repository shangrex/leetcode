class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];
        
        slow = nums[slow];
        fast = nums[nums[fast]];
        
        while(nums[slow] != nums[fast]){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        
        int head = nums[0];
        while(head != slow){
            head = nums[head];
            slow = nums[slow];
        }
        
        return slow;
    }
};