class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        sort(arr.begin(), arr.end(), [x](int a, int b){
            if(abs(a-x) < abs(b-x)) return true;
            if(abs(a-x) == abs(b-x)) return a < b;
            else return false;
        });

        vector<int> ret;
        for(int i = 0;i < k; i++){
            ret.push_back(arr[i]);
        }
        sort(ret.begin(), ret.end());
        return ret;
    }
};