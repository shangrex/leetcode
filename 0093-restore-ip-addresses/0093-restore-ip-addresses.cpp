class Solution {
    /*
    bool valid(string s){
        // failure case 01, 1111,
        if(s.length() < 1 || s.length() > 3){
            return false;
        }
        else if(s.length() > 1 & s[0] == '0'){
            return false;
        }
        else {
            if(stoi(s) > 255){
                return false;
            }
        }
        return true;
    }

    void backtrack(string s, int idx, vector<string>&ret, string output, int numDot){
        if(numDot == 3){
            if(valid(s.substr(idx)))
                ret.push_back(output+s.substr(idx));
            return;
        }

        for(int i = idx; i < s.length(); i++){
            string t = s.substr(idx, i - idx+1);
            if(valid(t)){
                output += s[i];
                if(numDot < 3)
                    output.push_back('.');
                backtrack(s,i+1, ret, output, numDot+1);
             
                if(numDot < 3)
                    output.pop_back();
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        int numDot = 0;
        string output = "";
        backtrack(s, 0, ret, output, numDot);
        return ret;
    }
    */
public:
    bool valid(string t){
        if(t.length() > 3 || t.length() < 1){
            return false;
        }
        if(t[0] == '0' && t.length() > 1){
            return false;
        }
        if(stoi(t) > 255){
            return false;
        }
        return true;
    }
    void backtrack(string s,vector<string>& ret, int idx, string curStr, int numDot){
        if(numDot == 3){
            string tmp = s.substr(idx);
            if(valid(tmp)){
                curStr += tmp;
                ret.push_back(curStr);
            }
            return;
        }

        for(int i = 1; i < 4; i++){
            if(idx+i > s.length()) break;
            string tmpStr = s.substr(idx, i);
            // cout << idx << " " << tmpStr << endl;
            if(valid(tmpStr)){
                backtrack(s, ret, idx+i, curStr+tmpStr+".", numDot+1);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;

        int idx = 0;
        int numDot = 0;
        string curStr = "";

        backtrack(s, ret, idx, curStr, numDot);
        return ret;        
    }
};