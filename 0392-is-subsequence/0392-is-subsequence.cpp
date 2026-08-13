class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sIdx = 0, tIdx = 0;
        while(sIdx < s.length() && tIdx < t.length()){
            if(s[sIdx] == t[tIdx]){
                sIdx++;
                tIdx++;
            }
            else {
                tIdx++;
            }
        }

        if(sIdx == s.length()) return true;
        return false;
    }
};