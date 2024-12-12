// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    // 1 1 1 0 0
    // l         r
    //     m
    //       l
    //          m
    //          r
    //       m
    //       r
    int firstBadVersion(int n) {
        long long left = 0, right = n;
        while(left < right){
            long long m = (left+right)/2;
            if(!isBadVersion(m)){
                left = m+1;
            }
            else {
                right = m;
            }
        }
        return left;
    }
};