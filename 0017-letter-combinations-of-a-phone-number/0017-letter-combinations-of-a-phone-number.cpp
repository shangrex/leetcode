class Solution {
public:
    void backtrack(vector<string>&rst, unordered_map<char, vector<char>>&mp, string &digits, int index){
        if(index >= digits.size()) return;
        int n = rst.size();
        for(int i = 0; i < n; i++){
            string tmp = rst.back();
            rst.pop_back();
            for(auto &j : mp[digits[index]]){
                string tmp2 = tmp;
                tmp2 += j;
                //cout << tmp2 << endl;
                rst.insert(rst.begin(), tmp2);
            }
        }
        backtrack(rst, mp, digits, index+1);
    }
    
    vector<string> letterCombinations(string digits) {
        unordered_map<char, vector<char>> mp;
        mp['2'] = {'a', 'b', 'c'};
        mp['3'] = {'d', 'e', 'f'};
        mp['4'] = {'g', 'h', 'i'};
        mp['5'] = {'j', 'k', 'l'};
        mp['6'] = {'m', 'n', 'o'};
        mp['7'] = {'p', 'q', 'r', 's'};
        mp['8'] = {'t', 'u', 'v'};
        mp['9'] = {'w', 'x', 'y', 'z'};
        vector<string> rst;
        if(digits.length() == 0) return {};
        rst.push_back("");
        backtrack(rst, mp, digits, 0);
        return rst;
    }
};