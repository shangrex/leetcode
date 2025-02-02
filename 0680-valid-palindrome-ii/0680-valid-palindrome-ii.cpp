class Solution {
public:
    bool isCheck(string s, int l, int r, bool flag){
        while(l < r){
            if(s[l] != s[r] && flag){
                return isCheck(s, l+1, r, false) || isCheck(s, l, r-1, false);
            }
            else if(s[l] != s[r])return false;
            l++;
            r--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int l = 0, r = s.length()-1;
        return isCheck(s, 0, r, true);
    }
};