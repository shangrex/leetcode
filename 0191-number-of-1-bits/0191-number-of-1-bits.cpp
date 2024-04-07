class Solution {
public:
    /*
    Approach 1
    n&1
  int hammingWeight(int n) {
        int rst = 0;
        while(n){
            if(n&0x01 == 1)rst++;
            n = n >> 1;
        }
        return rst;
    }  
    
    Approach 2
    n&n-1
    */
    int hammingWeight(int n) {
        int rst = 0;
        while(n){
            rst ++;
            n = n&(n-1);
        }
        return rst;
    }
};