class Solution {
public:
    /*
    key points: need a counter to count the number of existed t value
    */
    bool check(unordered_map<char, int> &big, unordered_map<char, int> &small){
        if(big.size() != small.size())return false;
        for(auto i = big.begin(); i != big.end(); i++){
            if(big[i->first] < small[i->first])return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        if(s.length() < t.length())return "";
        string rst = "";
        int left = 0, right = 0;
        int rst_length = 0, rst_start = 0;
        unordered_map<char, int>map_t, map_s;
        for(int i = 0; i < t.length(); i++){
            map_t[t[i]] += 1;
        }
        while(right < s.length()){
            while(!check(map_s, map_t) && right < s.length()){
                if(map_t.find(s[right]) != map_t.end()){
                    // exist
                    map_s[s[right]]++;
                }
                right++;
            }
            
           while(check(map_s, map_t) && left < right){
                if(map_s.find(s[left]) != map_s.end()){
                        // exist
                        map_s[s[left]]--;
                        if(map_s[s[left]] == 0)map_s.erase(s[left]);
                }
               if(rst_length == 0 || rst_length > right-left){
                   rst_start = left;
                   rst_length = right-left;
               }
               left++;
           }
        }
        if(left == 0)return "";
        rst = s.substr(rst_start, rst_length);
        return rst;
    }
};