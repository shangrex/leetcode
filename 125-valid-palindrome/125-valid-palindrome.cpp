class Solution {
public:
    /*
    A1
    A~Z = 65~90
    a~z = 97~122
    create a new correct string, use ASCII code to verify
    tow pointer to check, right pointer and left pointer check to middle
    */
    bool isPalindrome(string s) {
        string n = "";
        for(int i = 0; i < s.length(); i++){
            // A~Z
            if(s[i] > 64 && s[i] < 91){
                n += s[i] + 'a' - 'A';
            }
            // a~z
            else if(s[i] > 96 && s[i] < 123){
                n+=s[i];
            }
            // 0 ~ 9
            else if(s[i] >= 48 && s[i] <= 57){
                n += s[i];
            }
        }
        cout << n << endl;
        int front = 0, tail = n.length()-1;
        while(front < tail){
            if(n[front] == n[tail]){
                front ++;
                tail --;
            }
            else {
                return false;
            }
        }
        return true;
    }
};