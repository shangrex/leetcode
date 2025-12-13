class Solution {
public:
    string makeLargestSpecial(string s) {
        /*
        Reference: https://leetcode.com/problems/special-binary-string/submissions/1854255076/?envType=company&envId=nvidia&favoriteSlug=nvidia-three-months
        Reference: https://leetcode.com/problems/special-binary-string/solutions/113212/think-of-it-as-valid-parentheses-by-alex-rius/?envType=company&envId=nvidia&favoriteSlug=nvidia-three-months
        */
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