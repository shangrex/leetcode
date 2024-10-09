class Solution {
public:
    int minAddToMakeValid(string s) {
        int rst = 0;
        stack<char> st;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                st.push(s[i]);
            }
            else {
                if(st.empty()) rst++;
                else st.pop();
            }
        }
        rst += st.size();
        return rst;
    }
};