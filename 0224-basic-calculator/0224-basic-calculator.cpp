class Solution {
public:
    /*
        Approach 1. stack
        push the number and sign(1 or -1)
    */
    int calculate(string s) {
        int num = 0;
        int sign = 1;
        int ret = 0;
        stack<int>st;
        for(int i = 0; i < s.length(); i++){
            // 1 + (3 - 2))
            if(isdigit(s[i])){
                num = (s[i]-'0')+num*10;
            }
            else if(s[i] == '-'){
                ret += sign*num;
                sign = -1;
                num = 0;
            }
            else if(s[i] == '+'){
                ret += sign*num;
                cout << ret << endl;
                sign = 1;
                num = 0;
            }
            else if(s[i] == '('){
                st.push(ret);
                st.push(sign);
                sign = 1;
                num = 0;
                ret = 0;
            }
            else if(s[i] == ')'){
                ret += sign*num;
                sign = 1;
                num = 0;
                ret *= st.top();
                st.pop();
                ret += st.top();
                st.pop();
            }
        }

        ret += sign * num;
        return ret;
    }
};