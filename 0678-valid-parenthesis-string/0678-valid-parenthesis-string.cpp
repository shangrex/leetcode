class Solution {
public:
    /*
    Approach 1. DP
    Approach 2. two pointer
    
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
    
    */
    bool isvalid(vector<vector<int>>&memo,int index,int open, string &s){
        cout << index << " " << open << endl;
        if(index == s.length()){
            if(open == 0)return true;
            else return false;
        }
        if(memo[index][open] != -1) return memo[index][open];
        bool check = 0;
        if(s[index] == '*'){
            // '('
            check |= isvalid(memo, index+1, open+1, s);
            // ')'
            if(open > 0)
            check |= isvalid(memo, index+1, open-1, s);
            // ignore
            check |= isvalid(memo, index+1, open, s);
        }
        else if(s[index] == '('){
            check |= isvalid(memo, index+1, open+1, s);            
        }
        else if(s[index] == ')' && open > 0){
            check |= isvalid(memo, index+1, open-1, s);
        }
        
        memo[index][open] = check;
        return check;
        
    }
    bool checkValidString(string s) {
        int n = s.length();
        vector<vector<int>> memo(n+1, vector<int>(n+1, -1));
        
        return isvalid(memo, 0, 0, s);
        
    }
};