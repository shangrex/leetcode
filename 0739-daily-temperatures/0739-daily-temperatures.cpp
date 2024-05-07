class Solution {
public:
    /*
    Approach: Monotonic Stack
    Monotonic stack store the decreasing order of the number 
    */
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        vector<int>rst(temperatures.size(), 0);
        stack<int>st;
        for(int i = 0; i < temperatures.size(); i++){
            if(st.empty()){
                st.push(i);
            }
            else {
                while(!st.empty() && temperatures[st.top()] < temperatures[i]){
                    rst[st.top()] = i - st.top();                        
                    st.pop();
                }
                st.push(i);
            }
        }
        return rst;
        
    }
};