class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        string str_num = to_string(x);
        int l = 0, r = str_num.length()-1;
        while(l < r){
            if(str_num[l] != str_num[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};