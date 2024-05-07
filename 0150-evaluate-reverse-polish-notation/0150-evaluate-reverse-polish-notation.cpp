class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int rst = 0;
        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/"){
                cout << stoi(tokens[i]) << endl;
                st.push(stoi(tokens[i]));
                rst = st.top();
            }
            else {
                if(tokens[i] == "+"){
                    st.pop();
                    int t2 = st.top();
                    st.pop();
                    rst += t2;
                    st.push(rst);
                    cout << "push" << rst << endl;
                }
                else if(tokens[i] == "-"){
                    st.pop();
                    int t2 = st.top();
                    st.pop();
                    rst = t2 - rst;
                    st.push(rst);
                }
                else if(tokens[i] == "*"){
                    st.pop();
                    int t2 = st.top();
                    st.pop();
                    rst *= t2;
                    st.push(rst);
                    cout << "push*" << rst << endl;
                }
                else {
                    st.pop();
                    int t2 = st.top();
                    st.pop();
                    rst = t2 / rst;
                    st.push(rst);
                    cout << "push/" << rst << endl;
                }
            }
        }
        return rst;
    }
};