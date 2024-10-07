class Solution {
public:
    int minLength(string s) {
        bool flag = true;
        while(flag){
            flag = false;
            for(int i = 1; i < s.length(); i++){
                if(s[i] == 'B' && s[i-1] == 'A'){
                    s = s.substr(0, i-1) + s.substr(i+1);
                    flag = true;
                }
                else if(s[i] == 'D' && s[i-1] == 'C'){
                    s = s.substr(0, i-1) + s.substr(i+1);
                    flag = true;
                }
            }
        }
        return s.length();
    }
};