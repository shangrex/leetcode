class Solution {
public:
    /*
    Approach 1. monothonic dequeue + sliding window
        dequeue store the index of nums
        dequeu and pop both side
        ret look after dequeue front
        add value look after dequee tail
    */
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ret;

        for(int i = 0; i < k; i++){
            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        ret.push_back(nums[dq.front()]);

        
        for(int i = k; i < nums.size(); i++){
            // dq 2 k = 3
            // 3 4 5 
            while(!dq.empty() && i - dq.front() > k-1){
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            ret.push_back(nums[dq.front()]);
        }
        return ret;
    }
};