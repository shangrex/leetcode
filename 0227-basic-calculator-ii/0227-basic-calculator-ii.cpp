class Solution {
public:
    /*
    Hint: stack
    */
    int calculate(string s) {
        string cur_num = "";
        stack<int>st;
        char cur_op;
        s = "+" + s;
        for(int i = 0; i <= s.length(); i++){
            if(s[i] == ' ')continue;
            if(i < s.length() && isdigit(s[i])){cur_num = cur_num + s[i];}
            else {
                cout << s[i] << endl;
                // not number
                if(cur_num != ""){
                    if(cur_op == '+'){
                        int num = stoi(cur_num);
                        st.push(num);
                        cur_num = "";
                    }
                    else if(cur_op == '-'){
                        int num = stoi(cur_num);
                        st.push(-num);
                        cur_num = "";
                    }
                    else if(cur_op == '*'){
                        int t = st.top();
                        st.pop();
                        int num = stoi(cur_num);
                        //cout << t << "  " << num << endl;
                        st.push(t*num);
                        cur_num = "";
                    }
                    else if(cur_op == '/'){
                        int t = st.top();
                        st.pop();
                        int num = stoi(cur_num);
                        st.push(t/num);
                        cur_num = "";
                    }
                }
                
                cout << cur_op << endl;
                if(i < s.length())cur_op = s[i];
            }
            cout << cur_num << endl;
        }
        int rst = 0;
        if(cur_num != "") rst += stoi(cur_num);
        while(!st.empty()){
            int t = st.top();
            rst += t;
            st.pop();
        }
        return rst;
    }
};