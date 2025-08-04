class Solution {
public:
    // 1 1
    // 2 10
    // 4 100
    bool isPowerOfTwo(int n) {
        /*
        count the 1 bit of the number, if the count equal 1 than return true
        */
        if(n <= 0) return false;
        while(n){
            if(n&1 && n > 1) return false;
            n/=2;
        }
        return true;
    }
};