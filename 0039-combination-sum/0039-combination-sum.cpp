class Solution {
public:
    void dfs(vector<int>&candidates, int target, vector<vector<int>> &rst, vector<int>&tmp_rst){
        if(target == 0){
            rst.push_back(tmp_rst);
        }
        else if(target < 0)return ;
        for(int i = 0; i < candidates.size(); i++){
            if(!tmp_rst.empty() &&tmp_rst.back() > candidates[i])continue;
            tmp_rst.push_back(candidates[i]);
            dfs(candidates, target-candidates[i], rst, tmp_rst);
            tmp_rst.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> >rst;
        vector<int>tmp_rst;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, rst, tmp_rst);
        return rst;
    }
};