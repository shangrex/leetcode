class Solution {
public:
    bool isAnagram(string s, string t) {
        /*
        Approah 1. use two size of 26 vector to store count
        Approach2. use a unordered_map to balance the count
        */

        map<char, int>mp;
        for(auto i : s){
            mp[i]++;
        }
        for(auto i : t){
            mp[i]--;
        }

        for(auto i : mp){
            if(i.second != 0) return false;
        }
        return true;
    }
};