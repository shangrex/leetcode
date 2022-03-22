class Solution {
public:
    int binaryGap(int n) {
        int rst = 0;
        int dst = 0;
        bool flag = false;
        while(n>0){
            if(n & 1){
                // get 1
                if(flag){
                    dst += 1;
                    rst = max(rst, dst);
                }
                flag = true;
                dst = 0;
            }
            else if(flag){
                // get 0
                dst += 1;
            }
            n = n >> 1;
        }
        return rst;
    }
};