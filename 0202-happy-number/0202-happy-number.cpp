class Solution {
public:
    /*
    Appraoch 1. Hard code, observe only 1 and 7 did not have cycle when n < 10
    Approach 2. Detect cycle -> Floyd's cycle-finding
    Approach 3. Detect cycle -> hash map
    */
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