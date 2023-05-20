class Solution {
public:
    /*
    approach 1 brute force
    
    */
    int characterReplacement(string s, int k) {
        int rst = 0, max_f = 0, right = 0, left = 0;
        char tmp;
        unordered_map<char, int>mp;
        for(int right = 0; right < s.length(); right++){
            mp[s[right]]++;
            max_f = 0;
            for(auto i : mp)max_f = max(i.second, max_f);
            if(right-left-max_f+1 > k){
                mp[s[left]]--;
                left++;
            }
            rst = max(rst, right-left+1);
        }
        return rst;
    }
};