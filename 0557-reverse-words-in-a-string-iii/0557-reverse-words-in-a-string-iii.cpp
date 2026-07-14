class Solution {
public:
    /*
    Approach 1. 
    string reverseWords(string s) {
        stringstream ss(s);

        string ret = "", line = "";
        while(ss >> line){
            ret += " ";
            reverse(line.begin(), line.end());
            ret += line;
        }
        return ret.substr(1);
    }
    Approach 2.
    
    */
    string reverseWords(string s) {
        int lastspaceIdx = -1;
        int startIdx = 0, endIdx = 0;
        for(int i = 0; i <= s.length(); i++){
            if(s[i] == ' ' || i == s.length()){
                endIdx = i-1;
                startIdx = lastspaceIdx + 1;
                while(startIdx < endIdx){
                    char tmp = s[startIdx];
                    s[startIdx] = s[endIdx];
                    s[endIdx] = tmp;
                    startIdx++;
                    endIdx--;
                }
                lastspaceIdx = i;
            }
        }
        return s;
    }
};