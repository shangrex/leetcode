class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;
        unordered_map<char, int>mp;
        int rst = 0;
        while(right < s.length()){
            if(mp.find(s[right]) == mp.end()){
                mp[s[right]] = 1;
                rst =  max(rst, right - left+1);
                right++;
            }
            else {
                mp.erase(s[left]);
                left++;
            }
        }
        
        return rst;
    }
};