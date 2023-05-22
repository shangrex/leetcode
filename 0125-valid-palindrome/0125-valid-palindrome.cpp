class Solution {
public:
    bool isPalindrome(string s) {
        string tmp;
        for(int i = 0; i < s.length(); i++){
            // upper case
            if(s[i] >= 65 && s[i] <= 90){
                tmp.push_back(s[i]+32);
                
            }
            if(s[i] >= 97 && s[i] <= 122){
                tmp.push_back(s[i]);
            }
            if(s[i] >= 48 && s[i] <= 57){
                tmp.push_back(s[i]);
            }
        }
        int left = 0, right = tmp.length()-1;
        while(left < right && left < s.length() && right > -1){
            if(tmp[left] != tmp[right])return false;
            left++;
            right--;
        }
        return true;
        
    }
};