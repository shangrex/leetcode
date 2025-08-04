class Solution {
public:
    // 1 1
    // 2 10
    // 4 100
    bool isPowerOfTwo(int n) {
        /*
        Approach 1. count the 1 bit of the number, if the count equal 1 than return true.
        time lg2
        if(n <= 0) return false;
        while(n){
            if(n&1 && n > 1) return false;
            n/=2;
        }
        return true;
        Approach 2. bitwise operation
        n & -n -> all bit are reverted except the rightmost 1 bit
        5
        0101
        -5
        1011

        n & n-1 set the rightmost 1 bit to zero
        */
        if(n <= 0) return false;
        // return (n & -n) == n; or use
        return (n & n-1) == 0;
        
    }
};