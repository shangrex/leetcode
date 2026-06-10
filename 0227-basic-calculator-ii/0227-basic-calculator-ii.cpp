class Solution {
public:
    /*
    the difference betweeen basic calculator is the '(' and ')'

    Approach 1. Hint: stack
    store the last opeation & number
    if new number come in, check the latest operation & number
    in the end add all stack number together
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
    Approach 2. without stack

        int calculate(string s) {
        char op = '+';
        int n = s.length();
        int cur_num = 0, last_num = 0, ret = 0;
        int sign = 1;
        // when see '+' and '-' sum it all
        // see * - add to the tmp var

        for(int i = 0; i < n; i++){
            if(isdigit(s[i])){
                cur_num = (s[i]-'0')+cur_num * 10;
            }
            if((!isdigit(s[i]) && s[i] != ' ') || i == n-1){
                if(op == '+' || op == '-'){
                    ret += last_num;
                    last_num = (op == '+') ? cur_num : -cur_num;
                }
                if(op == '*' || op == '/'){
                    if(op == '*'){
                        last_num = last_num * cur_num;
                    }
                    else if(op == '/'){
                        //cout << last_num << " " << cur_num;
                        last_num = last_num / cur_num;
                    }
                }
                op = s[i];
                cur_num = 0;
            }
        }
        ret += last_num;
        return ret;
    }
    */
    /*
            char op = '+';
        int n = s.length();
        int cur_num = 0, last_num = 0, ret = 0;
        int sign = 1;
        // when see '+' and '-' sum it all
        // see * - add to the tmp var

        for(int i = 0; i < n; i++){
            if(isdigit(s[i])){
                cur_num = (s[i]-'0')+cur_num * 10;
            }
            if((!isdigit(s[i]) && s[i] != ' ') || i == n-1){
                if(op == '+' || op == '-'){
                    ret += last_num;
                    last_num = (op == '+') ? cur_num : -cur_num;
                }
                if(op == '*' || op == '/'){
                    if(op == '*'){
                        last_num = last_num * cur_num;
                    }
                    else if(op == '/'){
                        //cout << last_num << " " << cur_num;
                        last_num = last_num / cur_num;
                    }
                }
                op = s[i];
                cur_num = 0;
            }
        }
        ret += last_num;
        return ret;
    */
    int calculate(string s) {
        char ops = '+';
        long long curNum = 0, lastNum = 0;
        int ret = 0;
        for(int i = 0; i < s.length(); i++){
            if(isdigit(s[i])){
                curNum = curNum*10 + s[i]-'0';
            }

            if((!isdigit(s[i]) && s[i] != ' ') || i == s.length()-1){
                if(ops == '+' || ops == '-'){
                    ret += lastNum;
                    if(ops == '+') lastNum = curNum;
                    if(ops == '-') lastNum = -curNum;
                }
                if(ops == '*' || ops == '/'){
                    if(ops == '*') lastNum *= curNum;
                    if(ops == '/') lastNum /= curNum;
                }
                ops = s[i];
                curNum = 0;
            }
        }
        // cout << ret << endl;
        ret += lastNum;

        return ret;
    }
};