class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t  tmp = 0x80000000, rst=0;
        for(int i = 0; i < 32; i++){
            if(n&tmp)rst|=1<<i;
            tmp = tmp >> 1;
        }
        return rst;
    }
};