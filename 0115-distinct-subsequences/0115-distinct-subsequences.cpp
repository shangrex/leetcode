class Solution {

public:
    /*
    Approach 1. Top down
    func(i, j) = func(i+1, j+1) + func(i+1, j)

    unordered_map<string, int> memo;    
    int numDistinct(string s, string t) {
        if(s == t || t.empty()) return 1;
        if(s.size() < t.size()) return 0;
        int n = s.size(), m = t.size();
        string key = s + "," + t;
        if(memo.find(key) != memo.end()) return memo[key];

        int rst = numDistinct(s.substr(0, n-1), t);
        if(s[n-1] == t[m-1]){
            rst += numDistinct(s.substr(0, n-1), t.substr(0, m-1));
        }

        memo[key] = rst;
        return rst;
    }

    Approach 2. Bottom-up

    */
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<unsigned int>> dp(m+1, vector<unsigned int>(n+1, 0));

        // init
        //  0 ~  n
        // 0
        // |.  
        // m 1 ...1
        for(int i = 0; i <= m; i++){
            dp[i][n] = 0;
        }
        for(int i = 0; i <= n; i++){
            dp[m][i] = 1;
        }

        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                dp[i][j] = dp[i][j+1];
                if(t[i] == s[j]){
                    dp[i][j] += dp[i+1][j+1];
                }
            }
        }
        

        return dp[0][0];
    }
};