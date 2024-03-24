class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1, st2;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '#' && !st1.empty())st1.pop();
            else if(s[i] != '#')st1.push(s[i]);
        }
        for(int i = 0; i < t.length(); i++){
            if(t[i] == '#' && !st2.empty())st2.pop();
            else if (t[i] != '#')st2.push(t[i]);
        }
        if(st1.size() != st2.size())return false;
        int l = min(st1.size(), st2.size());
        for(int i = 0; i < l; i++){
            char t1 = st1.top(), t2 = st2.top();
            if(t1 != t2) return false;
            st1.pop();
            st2.pop();
        }
        return true;
    }
};