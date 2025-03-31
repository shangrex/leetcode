class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        for(auto i : s){
            if(!st.empty() && st.top() == i){
                st.pop();
            }
            else st.push(i);
        }


        string ret = "";
        while(!st.empty()){
            ret += st.top();
            st.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};