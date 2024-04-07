class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>rst(n+1, 0);
        for(int i = 0; i <= n; i++){
            rst[i] = __builtin_popcount(i);
        }
        return rst;
    }
};