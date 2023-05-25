class Solution {
public:
    /*
    1~3 win
    4 lost
    5 = 1+4 = win
    6 = 2+4 = win
    7 = 3+4 = win
    8 = lose
    9 = 1+8 = win
    
    */
    bool canWinNim(int n) {
        return n%4;
    }
};