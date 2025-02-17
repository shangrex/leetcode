class Solution {
public:
    /*
    1. Convert to string
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
    2. 
        if(x < 0) return false;
    // revert and compare
    long long cnt_dig = 1, cnt = 0;
    while(cnt_dig <= x) {cnt_dig*=10;cnt++;}
    long long t = 0, y=x;
    for(int i = 0; i < cnt; i++){
        t*=10;
        t+=(x%10);
        x/=10;
    }
    return t==y;


    */
    bool isPalindrome(int x) {
        if(x < 0 || (x%10 == 0 && x != 0)) return false;
        int rev_num = 0;
        // #count digit
        // transform the tmp
        while(rev_num < x){
            rev_num = x%10+rev_num*10;
            x/=10;
        }
        return rev_num == x || rev_num/10 == x;

    }
};