class Solution {
public:
    int myAtoi(string s) {
        int idx = 0;
        int sign = 1;
        while(s[idx] == ' ') idx++;
        if(s[idx] == '+'){
            sign = 1;
            idx++;
        }
        else if(s[idx] == '-'){
            sign = -1;
            idx++;
        }

        int base = 0;
        long long accNum = 0, unitDigit = 0;
        // cout << s[idx] << idx  << endl;
        cout << sign << endl;
        while(isdigit(s[idx])){
            if(accNum > INT_MAX/10 || (accNum == INT_MAX/10 && s[idx] > '7') 
                || accNum * sign < INT_MIN/10 || (accNum == INT_MIN/10 && s[idx] > '7') ){
              if(sign > 0) {cout << 'f' << endl;return INT_MAX;}
                else {return INT_MIN;}
            }
            accNum = 10 * accNum + (s[idx] - '0');
            idx++;
        }
        return accNum * sign;
    }
};