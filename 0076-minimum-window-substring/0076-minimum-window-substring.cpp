class Solution {
public:
    /*
    approach 1: use two unordered map to compare if t is in the substring of s
    approach 2: change the approach 1 methods to counter of t, counter equal to the length of the t, and if the counter equal to zero then t is in s.
    */
    bool check(unordered_map<char, int> &big, unordered_map<char, int> &small){
        if(big.size() != small.size())return false;
        for(auto i = big.begin(); i != big.end(); i++){
            if(big[i->first] < small[i->first])return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        string rst = "";
        int left = 0, right = 0, counter = t.length();
        int rst_length = 0, rst_start = 0;
        unordered_map<char, int>mp;
        for(int i = 0; i < t.length(); i++){
            mp[t[i]] += 1;
        }
        while(right < s.length()){
            if(mp[s[right]] > 0)counter--;
            mp[s[right]] -= 1;
            right++;
            while(counter == 0){
                if(rst_length == 0 || rst_length > right-left){
                   rst_start = left;
                   rst_length = right-left;
                }
                mp[s[left]]++;
                if(mp[s[left]] > 0)counter++; 
                left++;
            }
        }
        if(left == 0)return "";
        rst = s.substr(rst_start, rst_length);
        return rst;
    }
};