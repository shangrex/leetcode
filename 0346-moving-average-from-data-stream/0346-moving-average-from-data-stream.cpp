class MovingAverage {
public:
    /*
    Approach 1. queue
    O(M*N) M next times, N is windows size
    space O(N)
    int size;
    double sum;
    queue<int>q;

    MovingAverage(int size) {
        this->size = size;
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
    Approach 2. dequee
    T:O(M)
    S:O(N)
        int size;
    double sum;
    deque<int>q;

    MovingAverage(int size) {
        this->size = size;
        sum = 0;
    }
    
    double next(int val) {
        q.push_back(val);
        sum += (double)val;

        if(q.size() > this->size){
            sum -= q.front();
            q.pop_front();
        }
        return sum / q.size();
    }

    Approach 3. circular queue
    The major advantage of circular queue is that by adding a 
    new element to a full circular queue,
     it automatically discards the oldest element
    */
    int size;
    double sum;
    vector<int>q;
    int head;
    int cnt;

    MovingAverage(int size) {
        this->size = size;
        sum = 0;
        q = vector<int>(size);
        head = 0;
        cnt = 0;
    }
    
    double next(int val) {
        cnt++;
        int tail = (head + 1) % this->size;
        sum += (double)val;
        sum -= (double)q[tail];
        head = (head+1) % this->size;
        // replace the tail one
        q[head] = val;



        return sum / min(cnt, (int)q.size());
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */