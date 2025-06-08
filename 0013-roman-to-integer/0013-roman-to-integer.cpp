class Solution {
public:
    int romanToInt(string s) {
        int ret = 0;

        unordered_map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        for(int i = 0; i < s.length(); i++){
            if(i != s.length()-1){
                if(s[i] == 'I' && (s[i+1] == 'V' || s[i+1] == 'X')){
                    ret -= mp[s[i]];
                }
                else if(s[i] == 'X' && (s[i+1] == 'L' || s[i+1] == 'C')){
                    ret -= mp[s[i]];
                }
                else if(s[i] == 'C' && (s[i+1] == 'D' || s[i+1] == 'M')){
                    ret -= mp[s[i]];
                }
                else {
                    ret += mp[s[i]];
                }
            }
            else {
                ret += mp[s[i]];
            }
        }

        return ret;
    }
};