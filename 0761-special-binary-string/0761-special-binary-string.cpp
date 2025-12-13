class Solution {
public:
    string makeLargestSpecial(string s) {
        int cnt = 0,  i = 0;
        vector<string> pool;
        for(int j = 0; j < s.length(); j++){
            if(s[j] == '1') cnt++;
            else cnt --;

            if(cnt == 0){
                // 10111000
                //.  2    7
                //      
                pool.push_back('1' + makeLargestSpecial(s.substr(i+1, j-1-i)) + '0');
                i = j+1;
            }
        }
        string ret = "";
        sort(pool.begin(), pool.end(), greater<string>());
        for(int k = 0; k < pool.size();k ++){
            ret += pool[k];
        }

        return ret;
    }
};