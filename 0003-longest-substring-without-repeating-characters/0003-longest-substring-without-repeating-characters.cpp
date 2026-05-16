class Solution {
public:
    /*
        int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;
        unordered_map<char, int> mp;
        int ret = 0;
        while(right < s.length()){
            mp[s[right]]++;
            if(mp[s[right]] > 1){
                while(mp[s[right]] > 1 && left < right){
                    mp[s[left++]]--;
                }
            }
            ret = max(ret, right - left +1);
            right++;
        }
        return ret;
    }
    */
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;
        unordered_map<char, int> mp;
        int ret = 0;
        int cnt_length = 0;
        while(right < s.length()){
            mp[s[right]]++;
            while(mp[s[right]] > 1){
                if(mp[s[left]] == 1){
                    mp.erase(s[left]);
                }
                else mp[s[left]]--;
                left++;
            }
            ret = max(ret, right-left+1);
            right++;
        }

        return ret;
    }
};