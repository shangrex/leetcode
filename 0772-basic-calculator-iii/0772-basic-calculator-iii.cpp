class Solution {
public:
    /*
    Approach 1. stack + recursive
    */
    int calculate(string s) {
       int idx = 0;
       return parseExpr(s, idx); 
    }

    int parseExpr(string &s, int& idx){
        stack<int> st;
        char ops = '+';
        
        for(; idx < s.length() && ops != ')'; idx++){
            if(s[idx] == ' ') continue;
            int curNum = 0;
            if(s[idx] == '(') {
                curNum = parseExpr(s, ++idx);
            }
            else {
                curNum = parseNum(s, idx);
            }

            if(ops == '+'){
                st.push(curNum);
            }
            else if(ops == '-'){
                st.push(-curNum);
            }
            else if(ops == '*'){
                int tmpTop = st.top();
                st.pop();
                st.push(tmpTop*curNum);
            }
            else if(ops == '/'){
                int tmpTop = st.top();
                st.pop();
                st.push(tmpTop/curNum);
            }
            ops = s[idx];
        }

        int ret = 0;
        while(!st.empty()){
            int tmpTop = st.top();
            ret += tmpTop;
            st.pop();
        }
        return ret;
    }

    int parseNum(string &s, int& idx){
        int curNum = 0;
        while(idx < s.length() && isdigit(s[idx])){
            curNum = curNum * 10 + s[idx]-'0';
            idx++;
        }
        return curNum;
    }

};