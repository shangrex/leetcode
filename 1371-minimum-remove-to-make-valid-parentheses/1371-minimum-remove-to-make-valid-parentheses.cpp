class Solution {
public:
    string minRemoveToMakeValid(string s) {
        /*
        Approach 1. 
        1. identify the index should be reomve
        2. remove from string

        Approach 2.
        1. 

        */
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
    }
};