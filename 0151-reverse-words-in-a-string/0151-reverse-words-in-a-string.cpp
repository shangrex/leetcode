class Solution {
public:
    string reverseWords(string s) {
        vector<string> vString;
        string ret;
        istringstream ss(s);
        string tmp;
        while(ss >> tmp){
            vString.push_back(tmp);
            tmp = "";
        }

        reverse(vString.begin(), vString.end());
        for(int i = 0; i < vString.size(); i++){
            ret += vString[i] + ' ';
        }
        ret.pop_back();

        return ret;
    }
};