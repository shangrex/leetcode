class Solution {
public:
    unordered_map<int, int> mark;
    int dp[3010][3001];

    int solver(vector<int>&stones, int idx, int prevJump){
        if(idx == stones.size()-1){
            return true;
        }
        // cout << idx << " " << prevJump << endl;
        if(dp[idx][prevJump] != -1) return dp[idx][prevJump];
        bool ret = false;
        if(mark.find(stones[idx] + prevJump) != mark.end()){
            // exist
            if(prevJump != 0)
                ret |= solver(stones, mark[stones[idx]+prevJump], prevJump);
        }
        if(mark.find(stones[idx] + prevJump+1) != mark.end()){
            // exist
            if(prevJump+1 != 0)
                ret |= solver(stones, mark[stones[idx]+prevJump+1], prevJump+1);
        }
        if(mark.find(stones[idx] + prevJump-1) != mark.end()){
            // exist
            if(prevJump-1 != 0)
                ret |= solver(stones, mark[stones[idx]+prevJump-1], prevJump-1);
        }
        return dp[idx][prevJump] = ret;
    }
    bool canCross(vector<int>& stones) {
        if(stones[1] - stones[0] != 1) return false;
        for(int i = 0; i < stones.size(); i++){
            mark[stones[i]] = i;
        }
        memset(dp, -1, sizeof(dp));
        return solver(stones, 1, 1);
    }
};