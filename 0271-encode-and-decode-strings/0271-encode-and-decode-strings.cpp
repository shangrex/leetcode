class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string rst;
        char non_ascii = char(257);
        for(int i = 0; i < strs.size(); i++){
            rst += strs[i]+ non_ascii;
        }
        return rst;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        char non_ascii = char(257);
        vector<string>rst;
        int tmp_head = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == non_ascii){
                rst.push_back(s.substr(tmp_head, i-tmp_head));
                tmp_head = i+1;
            }
        }
        return rst;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));