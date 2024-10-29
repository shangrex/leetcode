class Solution {
public:
    string removeOccurrences(string s, string part) {
        string x;
        int n = s.length(), m = part.length();
        for(int i = 0, j = 0; i < n; i++){
            x.push_back(s[i]);
            j++;
            if(j - m >= 0 && x.substr(j - m, m) == part){
                x = x.substr(0, j-m);    
                j = j-m;
            }
            //cout << x << endl;
        }
        return x;
    }
};