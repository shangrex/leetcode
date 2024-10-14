class Solution {
public:
    bool isHappy(int n) {
                  // 2. 4 16 37 58 89 
  while(true){
            // 1
            if(n < 10){
                if(n == 1 || n == 7) return 1;
                else return false;
            }
            int t = n;
            n = 0;
            while(t > 9){
                int tmp = (t%10)*(t%10);
                n+=tmp;
                t /= 10;
            }
            n+= t*t;
            cout << n << endl;
        }
        return false;
    }
};