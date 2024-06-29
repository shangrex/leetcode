class Solution {
public:
    /*
    Approach 1. recursive
    Approach 2. memo
    Approach 3. bottom-up
     */
    int countdist(string& word1, string& word2, int n1, int n2, vector<vector<int>>& memo){
        int rst = 0;
        if(n1 == -1){
            return n2+1;
        }
        else if(n2 == -1){
            return n1+1;
        }
        else if(memo[n1][n2] != -1){
            return memo[n1][n2];
        }
        else if(word1[n1] == word2[n2]){
            return countdist(word1, word2, n1-1, n2-1, memo);
        }
        else {
            // delete word2
            int op1 = countdist(word1, word2, n1-1, n2, memo);
            // insert 
            int op2 = countdist(word1, word2, n1, n2-1, memo);
            // replace
            int op3 = countdist(word1, word2, n1-1, n2-1, memo);
            rst = min({op1, op2, op3})+1;
            memo[n1][n2] = rst;
        }
        return rst;
    }
    int minDistance(string word1, string word2) {
        int n1 = word1.length(), n2 = word2.length();
        vector<vector<int>> memo(n1, vector<int>(n2, -1));
        return countdist(word1, word2, n1-1, n2-1, memo);
    }
};