class Solution {
public:
    /*
    Approach 1.
     bool isValid(string s) {
        stack<char> st;
        
        for(int i = 0; i < s.length(); i++){
            if(!st.empty() && s[i] == ')'){
                if(st.top() == '('){
                    st.pop();
                }
                else return false;
            }
            else if(!st.empty() && s[i] == ']'){
                if(st.top() == '['){
                    st.pop();
                }
                else return false;
            }
            else if(!st.empty() && s[i] == '}'){
                if(st.top() == '{'){
                    st.pop();
                }
                else return false;
            }
            else {
                st.push(s[i]);
            }
        }
        if(!st.empty())return false;
        return true;
    }
    */
    bool isValid(string s) {
        stack<char> st;
        
        for(char c : s){
            if(c == ')'){
                if(!st.empty() && st.top() == '('){
                    st.pop();
                }
                else return false;
            }
            else if(c == ']'){
                if(!st.empty() && st.top() == '['){
                    st.pop();
                }
                else return false;
            }
            else if(c == '}'){
                if(!st.empty() && st.top() == '{'){
                    st.pop();
                }
                else return false;
            }
            else {
                st.push(c);
            }
        }
        return st.empty();
    }
};