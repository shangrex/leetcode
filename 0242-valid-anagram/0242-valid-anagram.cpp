class Solution {
public:
    bool isAnagram(string s, string t) {
        int s_cnt[26], c_cnt[26];
        for(int i = 0; i < 26; i++){
            s_cnt[i] = 0;
            c_cnt[i] = 0;
        }
        
        for(int i = 0; i < s.length(); i++){
            s_cnt[s[i]-'a'] += 1;
        }
        
        for(int i = 0; i < t.length(); i++){
            c_cnt[t[i]-'a'] += 1;
        }
        
        for(int i = 0; i < 26; i++){
            if(s_cnt[i] != c_cnt[i]) return false;
        }
        return true;

    }
};