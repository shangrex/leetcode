class MyCircularQueue {
private:
    vector<int>q;
    int tail = -1, head = 0, max_size = 0;
public:
    MyCircularQueue(int k) {
        q.resize(k);
        max_size = k;
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }
        tail = (tail+1)%max_size;
        q[tail] = value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        if(head == tail) {head = 0, tail = -1;}
        else head = (head+1)%max_size;
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : q[head];
    }
    
    int Rear() {
        // cout << tail << endl;
        return isEmpty() ? -1 : q[tail];
    }
    
    bool isEmpty() {
        if(tail == -1)return true;
        else return false;
    }
    
    bool isFull() {
        // cout << head << " " << tail << endl;
        if(!isEmpty() && head == (tail+1)%max_size){
            return true;
        }
        else return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */