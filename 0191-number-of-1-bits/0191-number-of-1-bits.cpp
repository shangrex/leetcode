class Solution {
public:
    int hammingWeight(uint32_t n) {
        int rst=0;
        while(n){
            if(n&1)rst++;
            n>>=1;
        }
        return rst;
    }
};