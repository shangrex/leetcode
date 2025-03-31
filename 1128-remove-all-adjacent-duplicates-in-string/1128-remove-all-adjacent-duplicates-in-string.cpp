class Solution {
public:
    /*
    Hint: stack
    1.         
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
    */
    string removeDuplicates(string s) {
        string ret = "";

        for(auto i : s){
            if(!ret.empty() && ret[ret.length()-1] == i){
                ret.pop_back();
            }
            else {
                ret += i;
            }
        }
        return ret;
    }
};