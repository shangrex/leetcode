class Solution {
public:
    void backtrack(int idx, vector<int>&candidates, int &target, vector<vector<int>>&rst, vector<int>&pool, int cnt){
        if(cnt > target) return;
        if(cnt == target){
            rst.push_back(pool);
            return;
        }

        for(int i = idx; i < candidates.size(); i++){
            pool.push_back(candidates[i]);
            backtrack(i, candidates, target, rst, pool, cnt+candidates[i]);
            pool.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> rst;
        vector<int> pool;
        int cnt = 0;
        backtrack(0, candidates, target, rst, pool, cnt);
        
        return rst;
    }
};