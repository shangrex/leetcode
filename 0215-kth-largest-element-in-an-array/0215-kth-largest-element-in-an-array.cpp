class Solution {
public:
    /*
    counting sort
    */
    int findKthLargest(vector<int>& nums, int k) {
        // priority_queue<int>pq;
        // for(int i = 0; i < nums.size(); i++){
        //     pq.push(nums[i]);
        // }
        
        // int rst = pq.top();
        // for(int i = 0; i < k; i++){
        //     rst = pq.top();
        //     pq.pop();
        // }
        // return rst;

        int max_num, min_num;
        for(auto &num : nums){
            max_num = max(num, max_num);
            min_num = min(num, min_num);
        }
        // 6 1
        // 5
        // 
        int n = max_num - min_num + 1;
        // n = 6
        // 0~5

        vector<int> count_v(n+1, 0);
        for(auto& num : nums){
            count_v[num-min_num]++;
        }

        for(int i = n-1; i >= 0; i--){
            k -= count_v[i];
            if(k <= 0){
                return i+min_num;
            }
        }
        return -1;
    }
};