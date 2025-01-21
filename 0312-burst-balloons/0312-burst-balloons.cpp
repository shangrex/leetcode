class Solution {
public:
    /*
    Hint: Divid and Conquer
    make the middle one burst last and left and right part are independent
    */

    int dp(vector<vector<int>> &memo, vector<int>&nums, int left, int right){
        if(left > right) return 0;
        int max_coin = 0;
        if(memo[left][right] != -1) return memo[left][right];

        for(int i = left; i <= right; i++){
            int coin = nums[left-1]*nums[i]*nums[right+1];
            coin = coin + dp(memo, nums, left, i-1)+dp(memo, nums, i+1, right);
            max_coin = max(max_coin, coin);
        }
        memo[left][right] = max_coin;
        return max_coin;
    }   
    int maxCoins(vector<int>& nums) {
        // to avoid edge case
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        int n = nums.size();
        vector<vector<int>> memo(n+1, vector<int>(n+1, -1));
        return dp(memo, nums, 1, nums.size()-2);
    }
};