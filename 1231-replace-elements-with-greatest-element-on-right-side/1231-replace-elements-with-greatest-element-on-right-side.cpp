class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        if(arr.size() == 0) return {};
        int n = arr.size();
        int maxTmp = arr[n-1];
        for(int i = n-1; i >= 0; i--){
            int tmp = arr[i];
            arr[i] = maxTmp;
            maxTmp = max(maxTmp, tmp);
        }
        arr[n-1] = -1;
        return arr;
    }
};