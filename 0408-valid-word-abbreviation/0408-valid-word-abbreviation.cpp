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
            // word = "internationalization", 
            //                            p
            // abbr = "i12iz4n"
            //              q 
            // cout << p << q << endl;
            // cout << word[p] << abbr[q] << endl;
            if(isdigit(abbr[q])){
                if(num == 0 && abbr[q] == '0') return false;
                num = num*10 + (abbr[q]-'0');
                if(q == abbr.length()-1) {p += num; num =0;}
                q++;
            }
            else {
                p += num;
                if(word[p] == abbr[q]){
                    p++;
                    q++;
                }
                else return false;
                num = 0;
            }
        }
        cout << p << " " << q << endl;
        cout << word.length() << " " << abbr.length();
        return p == word.length() && q == abbr.length();
    }
};