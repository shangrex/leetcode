class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int p = 0, q = 0;
        while(p < word.size() && q < abbr.size()){
            if(word[p] == abbr[q]){
                p++;
                q++;
            }
            else if(word[p] != abbr[q] && !isdigit(abbr[q])) return false;
            else {
                int num_digit = 0;
                    // first zero
                if(abbr[q] == '0') return false;
                while(isdigit(abbr[q])){
                    num_digit = num_digit*10 + (abbr[q]-'0');
                    q++;
                }

                for(int i = 0; i < num_digit; i++){
                    p++;
                }
            }
        }
        if(p == word.size() && q == abbr.size()) return true;
        else return false;
    }
};