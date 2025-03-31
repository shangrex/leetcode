class Solution {
public:
    /*
    The number of positive integers which are missing 
    before the arr[idx] is equal to arr[idx] - idx - 1.
    1 2 3
    0 1 2

    [2,3,4,7,11]
     l       r
         m
           l r
           m
             l
             m
           r l
    */
    int findKthPositive(vector<int>& arr, int k) {
        int left = 0, right = arr.size()-1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            // cout << mid << endl;
            if(arr[mid] - mid - 1 < k){
                // 
                left = mid+1;
            }
            else {
                right = mid-1;
            }
        }
        // left = right + 1
        // arr[right] + k - (arr[right] - right - 1)
        // 
        return k+left;
    }
};