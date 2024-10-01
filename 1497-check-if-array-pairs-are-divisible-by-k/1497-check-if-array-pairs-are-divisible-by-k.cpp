class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int>remain(k, 0);
        for(int i = 0; i < arr.size(); i++){
            int idx = arr[i]%k;
            //cout << arr[i] << " " << idx << endl;
            if(idx < 0) idx+=k;
            remain[idx] += 1;
        }
        if(remain[0] % 2 == 1) return false;
        int l = 1, r = k-1;
        while(l < r){
            if(remain[l] != remain[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};