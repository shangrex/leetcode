class Solution {
public:
    
    bool dp(vector<vector<int>> &memo,int i, int j, string s, string p){
        int n = s.length(), m = p.length();
        if(memo[i][j] != -1)return memo[i][j];
        bool rst = false;
        if(j == p.length()) {
            return i == s.length();
        }
        else {
            bool flag = (i < s.length() && (s[i] == p[j] || p[j] == '.'));
            if(j+1 < p.length() && p[j+1] == '*'){
                // ignore * so dont need to compare s[i] & ignore s[j]
                rst = (dp(memo, i, j+2, s, p) || (flag && dp(memo, i+1, j, s, p)));
            }
            else {
                rst = flag && dp(memo, i+1, j+1, s, p);
            }
        }
        memo[i][j] = rst;
        return rst;
    }
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        vector<vector<int>> memo(n+1, vector<int>(m+1, -1));
        return dp(memo, 0, 0, s, p);
    }
};