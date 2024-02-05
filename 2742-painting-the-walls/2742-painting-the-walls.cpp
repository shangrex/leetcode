class Solution {
public:
    
    int dp(int i, int remain, vector<int>&cost, vector<int>&time, vector<vector<int>>&memo){

        if(remain <= 0){
            return 0;
        }
        
        if(i == cost.size()){
            return 1e9;
        }
        
        if(memo[i][remain] != -1){
            // cout << i << " " << remain << " " << memo[i][remain] << endl;
            return memo[i][remain];
        }
        
        int paint = cost[i] + dp(i+1, remain-1-time[i], cost, time, memo);
        int dontpaint = dp(i+1, remain, cost, time, memo);
        memo[i][remain] = min(paint, dontpaint);
        return memo[i][remain]; 
    }
    
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int>>memo(n, vector(n+1, -1));
        return dp(0, n, cost, time, memo);
    }
};