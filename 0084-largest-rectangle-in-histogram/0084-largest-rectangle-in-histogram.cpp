class Solution {
public:
    /*
    Hint: max area is lessfromleft and lessfromright
    Hint: iterate from the index of the height, and is the less part and the right part of the index
    
    Approach 1. brute force
    Approach 2. divide and conquer
        three sub cases
        1. minimun height index * (end - start+1)
        2. largest left part from but excluded minimun height index 
        3. largest right part
    Approach 3. stack
    */
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        st.push(-1);
        int rst = heights[0];
        for(int i = 0; i < heights.size(); i++){
            while(st.top()!=-1 && heights[st.top()] > heights[i]){
                int current_height = heights[st.top()];
                st.pop();
                int current_weight = i - st.top() -1;
                //cout << current_height << " " << current_weight << endl;
                rst = max(rst, current_height * current_weight);
            }
            st.push(i);
        }
        int n = heights.size();
        while(st.top()!=-1){
            int current_height = heights[st.top()];
            st.pop();
            int current_weight = n - st.top() -1;
            //cout << current_height << " " << current_weight << endl;
            rst = max(rst, current_height * current_weight);
        }
        return rst;
    }
};