class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right =0;
        int ret = 0;
        unordered_map<char, int> mp;
        while(right < s.length()){
            mp[s[right]]++;

            while(mp[s[right]] > 1){
                if(mp[s[left]] > 0) mp[s[left]]--;
                else mp.erase(s[left]);
                left++;
            }

            ret = max(right - left + 1, ret);

            right++;
        }
        return ret;
    }
};