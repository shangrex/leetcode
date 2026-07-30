class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        unordered_map<char, int> mp;
        for(int i = 0; i < 27; i++){
            mp['a'+i] = widths[i];
        }

        int ret = 1;
        int cntWidth = 0;
        int idx = 0;
        while(idx < s.length()){
            cntWidth += mp[s[idx]];
            if(cntWidth > 100){
                cntWidth = mp[s[idx]];
                ret++;
            }
            idx++;
        }

        return {ret, cntWidth};
    }
};