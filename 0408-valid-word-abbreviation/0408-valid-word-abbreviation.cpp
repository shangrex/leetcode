class Solution {
public:
/*
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

                p += num_digit;
            }
        }
       
        return p == word.size() && q == abbr.size();
*/
    bool validWordAbbreviation(string word, string abbr) {
        int p = 0, q = 0;
        int num = 0;
        while(p < word.length() && q < abbr.length()){
            if(word[p] == abbr[q]){
                p++;
                q++;
            }
            else if(word[p] != abbr[q] && !isdigit(abbr[q])) return false;
            else {
                int num = 0;
                if(abbr[q] == '0') return false;
                while(isdigit(abbr[q])){
                    num = num*10+(abbr[q]-'0');
                    q++;
                }
                p += num;
            }
        }

        return p == word.length() && q == abbr.length();
    }
};