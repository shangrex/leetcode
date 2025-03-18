class Solution {
public:
    string addStrings(string num1, string num2) {
        int left = num1.length()-1, right = num2.length()-1;
        int carry= 0;
        string ret = "";
        while(left >= 0 || right >= 0){
            int d1 = left >= 0 ? num1[left] - '0' : 0;
            int d2 = right >= 0 ? num2[right] - '0' : 0;
            int remain = (d1+d2) % 10;
            ret += char((remain + carry)%10 + '0');
            carry = (d1+d2+carry)/10;
            left--;
            right--;
        }

        if(carry != 0){
            ret += '1';
        }
        reverse(ret.begin(), ret.end());

        return ret;
    }
};