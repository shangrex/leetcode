class KthLargest {
public:
    /*
    Approach 1: Use priority_queue to maintain the vector
    
    Approach 2: Use sort to maintain vector
    */
    priority_queue<int, vector<int>, greater<int>>pq;
    int index;
    KthLargest(int k, vector<int>& nums) {
        index = k;
        for(auto &num : nums){
            pq.push(num);
            if(pq.size() > k)pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        
        if(pq.size() > index)pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */