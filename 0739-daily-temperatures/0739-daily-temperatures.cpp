class Solution {
public:
    /*
    Approach: Monotonic Stack
    Monotonic stack store the decreasing order of the number 
    */
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>rst(temperatures.size(), 0);
        stack<int>st;
        st.push(0);
        for(int i = 1; i < temperatures.size(); i++){
            while(!st.empty() && temperatures[st.top()] < temperatures[i]){
                // warmer
                rst[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return rst;
        
    }
};