class Solution {
public:
    
    void backtrack(vector<int>& candidates, int target, int index, vector<int>&pool, vector<vector<int>> &rst){
        
        int ans = 0;
        for(auto i : pool){
            ans += i;
            if(ans == target){
                rst.push_back(pool);
                return;
            }
            else if(ans > target)return;
        }
        
        for(int i = index; i < candidates.size(); i++){
            pool.push_back(candidates[i]);
            backtrack(candidates, target, i, pool, rst);
            pool.pop_back();
        }
        return;
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> rst;
        vector<int> pool;
        
        backtrack(candidates, target, 0, pool, rst);
        return rst;
    }
};