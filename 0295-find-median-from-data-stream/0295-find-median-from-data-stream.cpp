class MedianFinder {
public:
    priority_queue<int> mx_pq;
    priority_queue<int, vector<int>, greater<int>> mi_pq;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // we must ensure max heap larger than min heap
        // push element
        mx_pq.push(num);
        mi_pq.push(mx_pq.top());
        mx_pq.pop();
        if(mx_pq.size() < mi_pq.size()){
            mx_pq.push(mi_pq.top());
            mi_pq.pop();
        }
    }
    
    double findMedian() {
        if(mx_pq.size() == mi_pq.size()){
            return (double(mx_pq.top()) + double(mi_pq.top()))/2;
        }
        else {
            return mx_pq.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */