class Solution {
public:
    /*
    Hint:  but it does not guaranteed that maximizing Robot1 will minimize Robot 2! That's the trap for this question.
    
    */
    long long gridGame(vector<vector<int>>& grid) {
        long long minSum = LLONG_MAX;
        int m = grid[0].size();
        long long first_row = 0;
        long long second_row = 0;
        // add suffix sum for first row
        for(int i = 0; i < m; i++){
            first_row += grid[0][i];
        }
        for(int i = 0; i < m; i++){
            first_row -= grid[0][i];
            minSum = min(minSum, max(first_row, second_row));
            second_row += grid[1][i];
        }
        return minSum;
    }
};