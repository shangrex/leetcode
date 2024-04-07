class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t rst = 0;
        
        uint32_t mask = 1;
        for(int i = 0; i < 32; i++){
            if(mask & n){
                rst |= 1;
            }
            if(i<31)rst = rst << 1;
            mask  = mask << 1;
        }
        
        return rst;
    }                                  
};                    