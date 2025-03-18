class Solution {
public:
    string minRemoveToMakeValid(string s) {
        /*
        Approach 1. 
        1. identify the index should be reomve
        2. remove from string

        Approach 2.
        1. two pass, first pass remove ')', second pass remove '('

                int num = 0;
        string ret = "";
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                num++;
            }
            else if(s[i] == ')' && num > 0){
                num--;
            }
            else if(s[i] == ')'){
                continue;
            }
            ret += s[i];
        }

        string rev_ret =  "";
        num = 0;
        for(int i = ret.length()-1; i >= 0; i--){
            if(ret[i] == ')'){
                num++;
            }
            else if(ret[i] == '(' && num > 0){
                num--;
            }
            else if(ret[i] == '(') {
                continue;
            }
            rev_ret += ret[i];
        }
    
        reverse(rev_ret.begin(), rev_ret.end());
        return rev_ret;

        Approach 3. 
        one pass with stack

        stack<int> st;
        for(int i = 0; i < s.length(); i++){
            
            if(s[i] == '('){
                st.push(i);
            }
            else if(s[i] == ')'){
                if(!st.empty())st.pop();
                else {
                    s.erase(i, 1); i--;
                } 
            }
        }

        while(!st.empty()){
            s.erase(st.top(), 1);
            st.pop();
        }
        return s;


        Approach 4.
        first delete ')'
        delete right most '('
        */
        int left = 0;
        for(int i = 0; i < s.length(); i++){
            
            if(s[i] == '('){
                left++;
            }
            else if(s[i] == ')'){
                if(left > 0)left--;
                else {
                    s.erase(i, 1); i--;
                } 
            }
        }

        while(left > 0){
            int pos = s.rfind('(');
            s.erase(pos, 1);
            left--;
        }
        return s;
    }
};