class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];
        bool flag = true;
        while(slow != fast || flag){
            cout << slow << " " << fast << endl;
            slow = nums[slow];
            fast = nums[nums[fast]];
            flag = false;
        }
        
        int cur = nums[0];
        while(cur != fast){
            cur = nums[cur];
            fast = nums[fast];
        }
        return cur;
    }
};