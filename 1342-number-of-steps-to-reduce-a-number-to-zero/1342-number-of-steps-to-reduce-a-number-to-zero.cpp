class Solution {
public:
    int numberOfSteps(int num) {
        int rst = 0;
        while(num>0){
            if(num%2==1){
                rst += 1;
                num -=1;
            }
            else {
            num >>= 1;
            rst += 1;
            }
        }
        return rst;
    }
};