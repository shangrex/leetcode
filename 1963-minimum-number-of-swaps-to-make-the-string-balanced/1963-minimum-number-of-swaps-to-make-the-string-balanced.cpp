class Solution {
public:
    /*
    Hint: count the unbalanced count
    */
    int minSwaps(string s) {
        stack<char>st;
        int rst = 0;
        for(int i = 0; i < s.length(); i++){

            if(s[i] == '['){
                st.push(s[i]);
            }
            else {
                if(!st.empty()){
                    st.pop();
                } 
                else {
                    rst += 1;
                }
            }
        }
        return (rst+1)/2;
    }
};