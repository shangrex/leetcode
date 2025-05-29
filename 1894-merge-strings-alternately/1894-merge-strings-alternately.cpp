class Solution {
public:
/*
    string mergeAlternately(string word1, string word2) {
        int p = 0, q = 0;
        string ret = "";
        while(p < word1.size() && q < word2.size()){
            ret += word1[p];
            ret += word2[q];
            p++;
            q++;
        }

        if(p < word1.size()){
            ret += word1.substr(p);
        }
        else if(q < word2.size()){
            ret += word2.substr(q);
        }

        return ret;
    }
*/

    string mergeAlternately(string word1, string word2) {
        int p = 0, q = 0;
        string ret = "";
        while(p < word1.length() && q < word2.length()){
            ret += word1[p];
            ret += word2[q];
            p++;
            q++;
        }
        
        if(p < word1.length()){
            ret += word1.substr(p);
        }
        else ret += word2.substr(q);

        return ret;
    }
};