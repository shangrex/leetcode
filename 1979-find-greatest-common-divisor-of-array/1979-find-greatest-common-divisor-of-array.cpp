class Solution {
public:
    int gcd(int a, int b){
        if(a < b)switch(a, b);
        int t;
        while(b!=0){
            t=b;
            b=a%b;
            a=t;
        }
        return a;
    }
    int findGCD(vector<int>& nums) {
        int mi = nums[0], ma = nums[0];
        for(int i = 0; i < nums.size(); i++){
            mi = min(mi, nums[i]);
            ma = max(ma, nums[i]);
        }
        return gcd(mi, ma);
    }
};