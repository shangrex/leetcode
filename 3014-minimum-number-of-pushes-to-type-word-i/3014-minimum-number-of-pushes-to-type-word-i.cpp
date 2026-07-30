class Solution {
public:
    int minimumPushes(string word) {
        /*
        8 9-16 17-24 25-26
        8. 2*8.  8*3. 2*4
        8.  24
        */

        int n = word.length();
        if(n < 9){
            return n;
        }
        else if(n < 16){
            return 8 + 2*(n-8);
        }
        else if(n < 25){
            return 24 + 3 * (n-16);
        }
        else if(n < 27){
            return 48 + 4*(n-24);
        }
        return -1;
    }
};