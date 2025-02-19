class Solution {
    /*
    First solution
     string toGoatLatin(string sentence) {
        string rst = "";
        string ap_a = "";
        bool flag = true;
        while(flag){
            int sp = sentence.find(' ');
            cout << sp << endl;
            if(sp < 0)flag = false;
            string sp_str = sentence.substr(0, sp);
            sentence = sentence.substr(sp+1);
            ap_a.append("a");
            if(sp_str[0] == 'a' || sp_str[0] == 'e' || sp_str[0] == 'i' ||
                sp_str[0] == 'o' || sp_str[0] == 'u' || sp_str[0] == 'A' || 
                sp_str[0] == 'E' || sp_str[0] == 'I' ||
                sp_str[0] == 'O' || sp_str[0] == 'U'){
                    sp_str.append("ma");
                }
            else {
                // remove first letter
                string ap_str = sp_str.substr(0, 1);
                sp_str = sp_str.substr(1).append(ap_str+"ma");
            }

            sp_str.append(ap_a);
            if(flag)rst.append(sp_str+" ");
            else rst.append(sp_str);
        }        
        return rst;
    }

    Approach 2.
    private:
    const set<char> vowels {'a', 'e', 'i', 'o', 'u',
                            'A', 'E', 'I', 'O', 'U'};
    public:
    string toGoatLatin(string sentence) {
       string rst, tok, suff;
       istringstream ss(sentence);
       while(ss >> tok){
            suff += 'a';
            if(vowels.count(tok[0]) <= 0){
                tok = tok.substr(1) + tok[0];
            }
            rst = rst + tok + "ma" + suff + ' ';
       }
        // pop the empty ' '
        rst.pop_back();
       return rst;
    }
    */
    private:
        set<char> vowels = {'a', 'e', 'i', 'o', 'u',
                            'A', 'E', 'I', 'O', 'U'};
    public:
    string toGoatLatin(string sentence) {
        string ret = "";
        string append_a = "";
        stringstream ss(sentence);
        string line = "";
        while(ss >> line){
            append_a += "a";
            if(vowels.count(line[0]) == 0){
                line = line.substr(1) + line.substr(0,1);
            }
            ret += line+ "ma"+ append_a + " ";
        }
        ret.pop_back();
        
        return ret;
    }
};