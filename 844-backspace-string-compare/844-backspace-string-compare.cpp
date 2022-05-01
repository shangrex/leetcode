class Solution {
public:
    /*
    method 1 
    use stack to operate string and compare
    method 2
    trace the two string from the string end to string front (two pointer method)
    */
    bool backspaceCompare(string s, string t) {
        vector<char> sv, tv;
        
        for(int i = 0; i < s.length(); i++){
            if(s[i] != '#')
            sv.push_back(s[i]);
            else if(!sv.empty())
            sv.pop_back();
        }

        for(int j = 0; j < t.length(); j++){
            if(t[j] != '#')
            tv.push_back(t[j]);
            else if(!tv.empty())
            tv.pop_back();
        }
        
        if(sv.size() != tv.size()) return false;
        int l = sv.size();
        for(int i = 0; i < l; i++){
            if(sv[i] != tv[i])return false;
        }
        return true;
    }
};