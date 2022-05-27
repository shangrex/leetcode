class Solution {
public:
    int hammingWeight(uint32_t n) {
        int rst = 0;
        while(n > 0){
            if(n%2==1){
                rst += 1;
            }
            n >>=1;
        }
        return rst;
    }
};