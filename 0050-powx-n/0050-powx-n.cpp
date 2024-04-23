class Solution {
public:
    /*
    Approach 1. brute force
        if(m == 1)return x;
        else if(m == 0) return 1;
        else if(m < 0) return 1 / x*myPow(x, m+1);
        return x*myPow(x, m-1);
        
        problem -> stack overflow
        
    Approach 2. 
    */
    double binaryExp(double x, long long int m){
        if(m == 0) return 1;
        if(m == 1) return x;
        
        if(m < 0){
            x = 1.0 / x;
            m *= -1;
        }
        
        double rst = 1;
        while(m){
            if(m % 2 == 1){
                rst *= x;
                m -=1;
            }
            x *= x;
            m /= 2;
        }
        return rst;
    }
    
    double myPow(double x, int m) {
        return binaryExp(x, (long long )m);
    }
};