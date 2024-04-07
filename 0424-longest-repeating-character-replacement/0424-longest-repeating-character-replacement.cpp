class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, right = -1;
        vector<int>count(26, 0);
        // the minimal changes means to use max_char_count
        int max_char_count = 0;
        int rst = 0;
        // awaare of comparison of signed int and unsigned int
        int n = s.length();
        
        while(right < n-1){
            right++;
            count[s[right]-'A']++;
            for(auto i : count)max_char_count = max(max_char_count, i);
            
            while(right-left+1-max_char_count > k){
                count[s[left]-'A']--;
                left++;
                for(auto i : count)max_char_count = max(max_char_count, i);
                
            }
            
            rst = max(rst, right - left + 1);
        }
        return rst;
    }
};