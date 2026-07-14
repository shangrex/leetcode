class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);

        string ret = "", line = "";
        while(ss >> line){
            ret += " ";
            reverse(line.begin(), line.end());
            ret += line;
        }
        return ret.substr(1);
    }
};