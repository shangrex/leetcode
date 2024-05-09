class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;
        unordered_map<char, int>mp;
        int rst = 0;
        while(right < s.length()){
            if(mp.find(s[right]) != mp.end()){
                mp[s[right]]++;
            }
            else mp[s[right]] = 1;
            
            while(mp[s[right]] > 1){
                if(mp[s[left]] == 1)mp.erase(s[left]);
                else mp[s[left]]--;
                left++;
            }
            // cout << left << " " << right << endl;
            rst = max(rst, (right-left+1));
            right++;
        }
        return rst;
    }
};