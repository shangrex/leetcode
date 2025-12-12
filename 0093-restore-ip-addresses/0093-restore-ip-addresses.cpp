class Solution {
public:
    
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
};