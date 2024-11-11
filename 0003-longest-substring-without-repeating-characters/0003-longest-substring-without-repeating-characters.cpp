class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left, right = 0;
        int rst = 0;
        unordered_map<char, int> mp;
        while(right < s.length()){
            mp[s[right]]++;

            while(mp[s[right]] > 1){
                if(mp[s[left]] == 1)mp.erase(s[left]);
                else mp[s[left]]--;
                left++;
            }

            rst = max(rst, right-left+1);
            right++;
        }
        return rst;
    }
};