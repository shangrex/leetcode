class Solution {
public:
    /*
    Approach 1. DP
    Approach 2. two pointer
    */
    bool checkValidString(string s) {
        int left = 0, right = s.length()-1;
        int open = 0, close = 0;
        while(left < s.length()){
            if(s[left] != ')')open++;
            else open --;
            if(s[right] != '(')close++;
            else close --;
            if(open < 0 || close < 0)return false;
            left++;
            right--;
        }
        return true;
        
    }
};