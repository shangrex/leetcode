class Solution {
public:
    /*
    n = 5, k = 2
    [1, 2, 3, 4, 5]
    [1]
    */
    

    void backtrack(int n, int k, vector<vector<int>> &ret, vector<int>&pool, int idx){
        if(idx > n){
            if(pool.size() == k)ret.push_back(pool);
            return;
        }
        else if(pool.size() == k){
            ret.push_back(pool);
            return;
        }

        backtrack(n, k, ret, pool, idx+1);
        pool.push_back(idx);
        backtrack(n, k, ret, pool, idx+1);
        pool.pop_back();
    }
    
    vector<vector<int>> combine(int n, int k) {
        int idx = 1;
        vector<vector<int>> ret;
        vector<int>pool;
        backtrack(n, k, ret, pool, idx);
        return ret;
    }
};