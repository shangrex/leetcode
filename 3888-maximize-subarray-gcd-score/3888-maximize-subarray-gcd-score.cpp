class Solution {
public:
// 3 6 9
// 0 1 0
// l
// 3
//     r
    long long maxGCDScore(vector<int>& nums, int k) {

        int n = nums.size();
        long long ret = 0;

        // count power of two
        vector<int> power2Vector(n);
        for(int i = 0; i < n; i++){
            int tmp = nums[i];
            while(tmp % 2 == 0){
                power2Vector[i]++;
                tmp/=2;
            }
        }
        for(int i = 0 ; i < n; i++){
            int cntPower2 = 0, gcdValue = 0, power2 = INT_MAX;
            for(int j = i; j < n; j++){
                gcdValue = gcd(nums[j], gcdValue);
                if(power2 > power2Vector[j]){
                    power2 = power2Vector[j], cntPower2 = 1;
                }
                else if(power2 == power2Vector[j]){
                    cntPower2++;
                }
                if(cntPower2 <= k){
                    ret = max(ret, (long long)((j - i + 1) * 2 * (long long)gcdValue));
                }
                else {
                    ret = max(ret, (long long)((j - i + 1) *(long long)gcdValue));
                }
            }

        }
        return ret;
    }
};