class Solution {
public:
    vector<vector<int>>rst;
    vector<int>pool;
    void backtrack(int index, int &target, int &sum_pool, vector<int>& candidates){
        
        if(sum_pool == target){
            rst.push_back(pool);
        }
        
        for(int i = index; i < candidates.size(); i++){
            if(i != index && candidates[i] == candidates[i-1])continue;
            if(sum_pool < target){
                pool.push_back(candidates[i]);
                sum_pool += candidates[i];
                backtrack(i+1, target, sum_pool, candidates);
                pool.pop_back();
                sum_pool -= candidates[i];
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int sum_pool = 0;
        backtrack(0, target, sum_pool, candidates);
        
        return rst;
    }
};