class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char>mp;
        int j = 0;
        for(int i = 0 ; i < key.length(); i++){
            if(key[i] == ' ')continue;
            char c = char('a'+j);
            if(mp.find(key[i]) == mp.end()){
                mp[key[i]] = c;
                cout << key[i] << " " << c << endl;
                j++;
            }
        }
        string rst = "";
        for(int i = 0; i < message.length(); i++){
            if(message[i] == ' ') rst += " ";
            else rst += mp[message[i]];
        }
        return rst;

    }
};