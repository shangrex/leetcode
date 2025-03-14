class Solution {
public:
    /*
    Hint: stack
    store the last opeation & number
    if new number come in, check the latest operation & number
    in the end add all stack number together
    */
    int calculate(string s) {
        string cur_num = "";
        stack<int>st;
        char cur_op = '+';
        for(int i = 0; i <= s.length(); i++){
            if(s[i] == ' ')continue;
            if(i < s.length() && (s[i] >= '0' && s[i] <= '9')){cur_num = cur_num + s[i];}
            else {
                //cout << s[i] << endl;
                // not number
                //cout << i << " " << cur_num << endl;
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
                        st.push(t*num);
                        cur_num = "";
                    }
                    else if(cur_op == '/'){
                        int t = st.top();
                        st.pop();
                        int num = stoi(cur_num);
                        st.push(t/num);
                        //cout << t / num << endl;
                        cur_num = "";
                    }
                }
            
                //cout << cur_op << endl;
                if(i < s.length())cur_op = s[i];
            }
             //cout << cur_num << endl;
        }
        int rst = 0;
        // rst += stoi(cur_num);
        while(!st.empty()){
            int t = st.top();
            rst += t;
            st.pop();
        }
        return rst;
    }
};