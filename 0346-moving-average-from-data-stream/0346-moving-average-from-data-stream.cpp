class MovingAverage {
public:
    int size;
    int cnt;
    double sum;
    queue<int>q;
    MovingAverage(int size) {
        this->size = size;
        this->cnt = 0;
        sum = 0.0;
    }
    
    double next(int val) {
        double sum = 0.0;
        q.push(val);
        if(q.size() > this->size) q.pop();
        queue<int>tq(q);
        while(!tq.empty()){
            sum += tq.front();
            tq.pop();
        }
        
        return sum / q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */