class Solution {
public:
    int lsp(string &s, int left, int right, vector<vector<int>>&memo){
        if(memo[left][right] != -1) {
            return memo[left][right];
        }
        if(left>right) return 0;
        else if(left == right) return 1;

        if(s[left] == s[right]){
            memo[left][right] = lsp(s, left+1, right-1, memo)+2;
        }
        else {
            memo[left][right] = max(lsp(s, left+1, right, memo), lsp(s, left, right-1, memo) );
        }

        return memo[left][right];

    }
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> memo(n+1, vector<int>(n+1, -1));

        return lsp(s, 0, n-1, memo);
    }
};