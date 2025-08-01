class Solution {
public:
    string decodeString(string s) {
        string ret = "";
        stack<string> stringStack;
        stack<int> intStack;
        int k = 0;
        for(int i = 0; i < s.length(); i++){
            
    
            if(isdigit(s[i])){
                k = k*10 + (s[i]-'0');
            }
            else if(s[i] == '['){
                intStack.push(k);
                stringStack.push(ret);
                ret = "";
                k = 0;
            }
            else if(s[i] == ']'){
                string decodeString = stringStack.top();
                stringStack.pop();
                int count = intStack.top();
                intStack.pop();
                // cout << count << endl;
                for(int j = 0; j < count; j++){
                    decodeString = decodeString + ret;
                }
                // cout << decodeString << endl;
                ret = decodeString;
            }
            else {
                ret += s[i];
            }
        }
        return ret;
    }
};