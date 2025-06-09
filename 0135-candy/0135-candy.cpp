class Solution {
public:
        /*
        Approach 1. two array with two pass
        Approach 1.5. one array with one pass
        Approach 2. slope methods
        */
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size(), 1);
        int n = ratings.size();
        for(int i = 1; i < n; i++){
            if(ratings[i] > ratings[i-1]){
                candies[i] = candies[i-1]+1;
            }
        }
        int ret = 0;
        for(int i = n-2; i >= 0; i--){
            if(ratings[i] > ratings[i+1]){
                candies[i] = max(candies[i+1]+1, candies[i]);
            }
                ret += candies[i];

        }
        ret += candies[n-1];
        return ret;
    }
};