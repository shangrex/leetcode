class MyQueue {
public:
    stack<int> input, output;
    MyQueue() {
    }
    
    void push(int x) {
        input.push(x);        
    }
    
    int pop() {
        int t = peek();
        output.pop();
        return t;
    }
    
    int peek() {
        if(output.empty()){
            while(!input.empty()){
                int tmp = input.top(); input.pop();
                output.push(tmp);
            }
        }
       
        return output.top();
    }
    
    bool empty() {
        if(input.empty() && output.empty()){
            return true;
        }
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */