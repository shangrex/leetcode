// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         // be careful division zero
//         vector<int>ans(nums.size(), 1);
//         long long int suffix = 1;
//         // prefix 
//         // 1 2 3 4
//         //   1 2 
//         //     8 4   1
//         //     
//         for(int i = 1; i < nums.size(); i++){
//             ans[i] = nums[i-1]*ans[i-1];
//         }
//         // suffix
//         for(int i = nums.size()-1; i > 0; i--){
//             suffix = suffix*nums[i];
//             ans[i-1] = ans[i-1]*suffix;
//         }
//         return ans;
//     }
// };
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long suffix = 1;
        int n = nums.size();
        vector<int>ans(n, 1);
        // 1 2 3 4
        //.1 1.2 6
        //       1
        for(int i = 1; i < n; i++){
            ans[i] = nums[i-1] * ans[i-1];
        }
        // for(int i = 0; i < n; i++){
        //     cout << ans[i] << " ";
        // }

        for(int i = n-1; i > 0; i--){
            suffix *= nums[i];
            ans[i-1] *= suffix;
        }

        return ans;
    }
};