class Solution {
public:
    bool isValid(string s) {
        if(s.length()%2==1)return false;
        stack<char>check;
        check.push('*');
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                check.push(s[i]);
                continue;
            }
            if(s[i] == ')'){
                if(check.top() == '(')check.pop(); 
                else return false;
            }
            else if(s[i] == '}'){
                if(check.top() == '{')check.pop(); 
                else return false;
            }
            else if(s[i] == ']'){
                if(check.top() == '[')check.pop(); 
                else return false;
            }
        }
        if(check.top() != '*')return false;
        return true;
    }
};