class Solution {
public:
    /*
    set + piroity queue
    */
    int thirdMax(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        set<int> st;
        for(int i = 0; i < nums.size(); i++){
            if(st.count(nums[i]) == 0)pq.push(nums[i]);
            st.insert(nums[i]);
            if(pq.size() > 3){
                pq.pop();
            }
        }
        int n = pq.size();
        for(int i = 0; i < 3-n; i++){
            pq.pop();
        }
        int ret = pq.top();
        return ret;
    }
};