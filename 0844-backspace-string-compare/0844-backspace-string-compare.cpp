class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>s_st, t_st;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '#'){
                if(!s_st.empty())s_st.pop();
            }
            else s_st.push(s[i]);
        }
        for(int i = 0; i < t.length(); i++){
            if(t[i] == '#'){
                if(!t_st.empty())t_st.pop();
            }
            else t_st.push(t[i]);
        }
        
        while(!s_st.empty()){
            if(t_st.empty())return false;
            char s_top = s_st.top();
            char t_top = t_st.top();
            if(s_top != t_top) return false;
            s_st.pop();
            t_st.pop();
        }
        if(t_st.empty())return true;
        else return false;
    }
};