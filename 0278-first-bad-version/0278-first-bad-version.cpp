// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long int first = 1, last = n;
        int rst = n;
        while(first < last){
            long long int mid = (first+last)/2;
            if(isBadVersion(mid)){
                rst = mid;
                last = mid;
            }
            else {
                first = mid+1;
            }
        }
        return rst;
    }

};