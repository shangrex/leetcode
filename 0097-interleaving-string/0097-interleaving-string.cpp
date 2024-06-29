class Solution {
public:

    bool ischeck(string s1, int i1, string s2, int i2, string& s3, int i3, vector<vector<int>>&memo){
        if(i1 < 0 && i2 < 0 && i3 < 0){
            return true;
        }
        if( i1> -1 && i2 > -1 && memo[i1][i2] != -1){
            if(memo[i1][i2] == 1) return true;
            else return false;
        }
        bool flag = false;
        // chose s1
        if(i1 >= 0 && i3 > -1 && s1[i1] == s3[i3])
            flag |= ischeck(s1, i1-1, s2, i2, s3, i3-1, memo);
        // choose s2
        if(i2 >= 0 && i3 > -1 && s2[i2] == s3[i3])
            flag |= ischeck(s1, i1, s2, i2-1, s3, i3-1, memo);

        if(i1 >= 0 && i2 >= 0){
            memo[i1][i2] = flag;
        }
        return flag;
    }
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>> memo(s1.length()+100, vector<int>(s2.length()+100, -1));
        return ischeck(s1, s1.length()-1, s2, s2.length()-1, s3, s3.length()-1, memo);
    }
};