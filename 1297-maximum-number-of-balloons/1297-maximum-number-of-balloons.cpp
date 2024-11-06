class Solution {
public:
    int maxNumberOfBalloons(string text) {
        // b 1
        // a 1
        // l 2
        // o 2
        // n 1
        unordered_map<char, int>mp;
        for (int i = 0; i < text.length(); i++) {
            mp[text[i]] += 1;
        }
        int rst = INT_MAX;
        // b
        rst = min(rst, mp['b']);
        rst = min(rst, mp['a']);
        rst = min(rst, mp['l']/2);
        rst = min(rst, mp['o']/2);
        rst = min(rst, mp['n']);
        
        if(rst == INT_MAX) return 0;
        else return rst;
    }
};