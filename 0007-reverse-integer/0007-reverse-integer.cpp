class Solution {
public:
    int reverse(int x) {
        // pop and push by using % and *
        long rst = 0;
        while(x){
            int pop = x % 10;
            rst = rst * 10 + pop;
            if(rst > INT_MAX)return 0;
            else if(rst < INT_MIN) return 0;
            x /= 10;    
        }
        return rst;
    }
};