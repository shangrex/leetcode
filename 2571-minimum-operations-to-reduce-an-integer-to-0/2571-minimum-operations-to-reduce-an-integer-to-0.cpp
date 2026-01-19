class Solution {
public:
    /*
    1, 2, 4, 8, 16, 32, 64
    
    approach 1. Substract the closet 2^n
    Greedy. We think finding the cloeset 2^n and substract it will be the less steps
    */
    int minOperations(int n) {
        int step = 0;
        while(n){
            int x = floor(log2(n));
            int y = ceil(log2(n));

            if(n - pow(2, x) >= pow(2, y) - n){
                // closer to ceil
                n = pow(2, y) - n;
            }
            else {
                // closer to floor
                n -= pow(2, x);
            }

            step ++;
        }
        return step;
    }
};