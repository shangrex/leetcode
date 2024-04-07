class Solution {
public:
    int hammingWeight(int n) {
        int rst = 0;
        while(n){
            if(n&0x01 == 1)rst++;
            n = n >> 1;
        }
        return rst;
    }
};