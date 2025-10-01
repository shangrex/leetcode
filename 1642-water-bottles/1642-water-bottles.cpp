class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        // 12 4
        // 3
        // 12 + 3= 15
        int ret = 0;
        int empty = 0;
        while(numBottles > 0){
            ret += numBottles;
            int t = (numBottles+empty) / numExchange;
            empty = (numBottles+empty)%numExchange;
            numBottles = t;
        }

        return ret;
    }
};