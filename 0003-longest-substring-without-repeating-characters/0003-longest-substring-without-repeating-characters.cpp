class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;
        unordered_map<char, int> mp;
        int ret = 0;
        while(right < s.length()){
            mp[s[right]]++;
            cout << mp[right];
            if(mp[s[right]] > 1){
                while(mp[s[right]] > 1 && left < right){
                    mp[s[left++]]--;
                    cout << left << endl;
                }
            }
            ret = max(ret, right - left +1);
            right++;
        }
        return ret;
    }
};