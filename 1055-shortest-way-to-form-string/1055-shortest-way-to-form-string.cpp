class Solution {
public:
    int shortestWay(string source, string target) {
        /*
        Approach 1. Greedy
        Time complexity O(M*N)
        Space complexity O(1)

        Appraoach2. 2D arary DP
        Time complexity O(M+N)
        TIme complexity O(S)
        */

        int n = source.length();
        int m = target.length();
        int nxtIdx[n][26];

        // initialzie last line of the nxtIdx. last seen character
        // x  y  z
        // -1 -1 2
        for(int i = 0; i < 26; i++){
            nxtIdx[n-1][i] = -1;
        }
        nxtIdx[n-1][source[n-1]-'a'] = n-1;

        for(int i = n-2; i >= 0; i--){
            // copy from last line
            for(int j = 0; j < 26; j++){
                nxtIdx[i][j] = nxtIdx[i+1][j];
            }
            // overwrite the value of seen character
            nxtIdx[i][source[i]-'a'] = i;
        }

        int ret = 1;
        int sourceIdx = 0;
        for(int i = 0; i < m; i++){
            // target character never appear in source
            if(nxtIdx[0][target[i]-'a'] == -1){
                return -1;
            }

            if(sourceIdx == n || nxtIdx[sourceIdx][target[i]-'a'] == -1){
                ret++;
                //cout << sourceIdx << " " << i << endl;
                sourceIdx = 0;
            }
            sourceIdx = nxtIdx[sourceIdx][target[i]-'a'] + 1;
            // cout << sourceIdx << " " << i <<endl;
        }
        return ret;
    }
};