class Solution {
public:
    /*
        unordered_map<char, int>mp;
        if(s.length() != t.length())return false;
        for(int i = 0; i < s.length(); i++){
            mp[s[i]]++;
            mp[t[i]]--;
        }
        for(auto i : mp){
            if(i.second != 0)return false;
        }
        return true;
    */
    /*
    method 1. count the number or alphabets, then see if stirng t match
    method 2. 
    */
    bool isAnagram(string s, string t) {
        vector<int> dp(26, 0);
        // count the number of alpabes in s
        for(int i = 0; i < s.length(); i++){
            dp[s[i]-'a'] += 1;
        }
        // compare the t and s
        for(int i = 0; i < t.length(); i++){
            dp[t[i]-'a'] -= 1;
        }
        
        // check dp
        for(int i = 0; i < 26; i++){
            if(dp[i] != 0)return false;
        }
        return true;
    }
};