class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int>count_t;
        for(auto i : t){
            count_t[i]++;
        }
        int right = 0, left = 0;
        int n = s.length();
        string rst = "";
        int required = count_t.size();
        int formed = 0;
        unordered_map<char, int> count_window;
        int rst_length = INT_MAX, rst_left = 0, rst_right = 0;
        while(right < n){
            count_window[s[right]]++;
            
            // checking condition is that all the element should appear and the number of frequecny should the same or larger
            if(count_t.find(s[right]) != count_t.end() && count_window[s[right]] == count_t[s[right]]){
                formed ++;
            }
            while(left <= right && formed == required){
                if(right-left+1 < rst_length) {
                    rst_left = left;
                    rst_right = right;
                    rst_length = right- left +1;
                }                
                count_window[s[left]]--;
                if(count_t.find(s[left]) != count_t.end() && count_window[s[left]] < count_t[s[left]]){
                    formed--;    
                } 
                left++;
            }
            right++;
        }
        if(rst_length == INT_MAX) return "";
        return s.substr(rst_left, rst_right - rst_left+1);
    }
};