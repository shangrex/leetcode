class Solution {
public:
    /*
    Approach 1. 
    two pass.
    first pass find closet left, second pass find closent right

    Time complexity O(N)
    Space O(1)
    */
    vector<int> shortestToChar(string s, char c) {
        int n = s.length();

        vector<int> ret(n, n);
        int pos = -n;
        for(int i = 0; i < n; i++){
            if(s[i] == c) pos = i;
            ret[i] = i - pos;
        }
        //pos = n+1;
        for(int i = pos-1; i >= 0; i --){
            if(s[i] == c) pos = i;
            ret[i] = min(ret[i], pos-i);
        }
        
        return ret;
    }
};