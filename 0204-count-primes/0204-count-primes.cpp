class Solution {
public:
    vector<bool> primeArray;
    int countPrimes(int n) {
        if(n < 3) return 0;
        for(int i = 0; i <= n; i++){
            primeArray.push_back(true);
        }

        for(int i = 2; i <= sqrt(n); i++){
            if(primeArray[i]){
                for(int j = i*i; j <= n; j+= i){
                    primeArray[j] = false;
                }
            }
        }
        int cnt = 0;
        for(int i = 2; i < n; i++){
            if(primeArray[i]) cnt ++;
        }
        return cnt;
    }
};