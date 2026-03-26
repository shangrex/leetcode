class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        string input = "";
        int i = 0;
        unordered_map<string, string> w2p; // word to pattern
        unordered_map<char, string> p2w;
        while(ss >> input){
            if(w2p.find(input) == w2p.end() && p2w.find(pattern[i]) == p2w.end()){
                // not exist
                w2p[input] = pattern[i];
                p2w[pattern[i]] = input;
            }
            else {
                // exist then check pattern
                if(p2w[pattern[i]] != input) return false;
            }
            i++;
        }
        if(i != pattern.length()) return false;
        return true;
    }
};