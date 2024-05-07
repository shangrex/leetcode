class MinStack {
public:
    /*
    Approach 1.
    stack<pair<int, int>>
    pair store the push element and the current minimal element
    
    Approch 2. two stack
    since there will repeatedly store the minimal element, use two stack
    one store the push element 
    another store the minimal element
    
    Approach 3. two stack
    one store the push element 
    another store the number of repeatedly element    
    */
    
    
    stack<int> st;
    stack<pair<int, int>> num_min_st;
    
    MinStack() {
            
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            num_min_st.push({val, 1});
            return;
        }
        
        
        st.push(val);
        
        pair<int, int> t = num_min_st.top();
        
        if(t.first < val)return;
        else if(t.first == val){
            t.second += 1;
            num_min_st.pop();
            num_min_st.push(t);
        }
        else {
            num_min_st.push({val, 1});
        }
    }
    
    void pop() {
        int st_top = st.top();
        st.pop();
        pair<int, int> t = num_min_st.top();
        
        if(st_top != t.first){
            return;
        }
        else if(st_top == t.first){
            if(t.second == 1){
                num_min_st.pop();
            }
            else {
                t.second -= 1;
                num_min_st.pop();
                num_min_st.push(t);
            }
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        pair<int, int> t = num_min_st.top();
        return t.first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */