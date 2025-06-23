class Solution {
public:

    int findSteps(long long n, long long n1, long long n2){
        int steps = 0;
        while(n1 <= n){
            steps +=  min(n+1, n2) - n1;
            n1 *= 10;
            n2 *= 10;
        }
        
        return steps;
    }
    int findKthNumber(int n, int k) {
        int curr = 1;
        k -= 1;
        while(k > 0){
            int steps = findSteps((long long)n, (long long)curr, (long long)curr+1);
            //cout << steps << endl;
            if(steps > k){
                curr *= 10;
                k -= 1;
            }
            else {
                curr += 1;
                k -= steps;
            }
        }
        return curr;
    }
};