class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>mp;
        int left = 0;
        int rst = 0;
        for(int i = 0; i < s.length(); i++){
            
            if(mp.find(s[i]) == mp.end()){
                // not exist
                mp[s[i]] = i;
            }
            else {
                // exist
                rst = max(rst, i-left);
                left = max(left, mp[s[i]]+1);
                mp[s[i]] = i;
            }
        }
        int n = s.length();
        rst = max(rst, n-left);
        return rst;
    }
};