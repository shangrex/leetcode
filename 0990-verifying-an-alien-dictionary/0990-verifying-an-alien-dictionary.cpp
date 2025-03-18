class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        /*
        Hint: apple app is false
        the shorter should be put in the former

        also, if the first character is different and good order
        then it should break this compare
        */
        unordered_map<char, int>mp;
        for(int i = 0;i < order.length(); i++){
            mp[order[i]] = i;
        }

        for(int i = 0; i < words.size()-1; i++){
            string s1 = words[i];
            string s2 = words[i+1];
            // s1 should be shorter
            int j;
            for( j = 0; j < s1.length(); j++){
                if(j >= s2.length()) return false;
                if(mp[s1[j]] > mp[s2[j]]) return false;
                else if(s1[j] != s2[j]) break;
            }
        }
        return true;
    }
};