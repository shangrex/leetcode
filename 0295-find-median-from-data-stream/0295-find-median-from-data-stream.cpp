class MedianFinder {
public:
    /*
    use two heap, max_heap maintain right smaller value, and min_heap maintain left bigger value
    
    */
    priority_queue<int>small_values;    
    priority_queue<int, vector<int>, greater<int>>big_values;
    MedianFinder() {
    }
    
    void addNum(int num) {
        small_values.push(num);
        big_values.push(small_values.top());
        small_values.pop();
        if(big_values.size() > small_values.size()){
            small_values.push(big_values.top());
            big_values.pop();
        }
    }
    
    double findMedian() {
        if(small_values.size() == big_values.size()){
            return (small_values.top() + big_values.top())/2.0;
        }
        else{
            return small_values.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */