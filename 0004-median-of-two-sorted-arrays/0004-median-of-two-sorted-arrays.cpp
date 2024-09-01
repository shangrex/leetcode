class Solution {
public:
    /*
    Approach 1. Merge Sort or two pointer
    Approach 2. Binary search
        * recursive 
        * while loop
    */
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int length_a = nums1.size(), length_b = nums2.size();
//         int target_idx = (length_a+length_b)/2;
//         if((length_a+length_b)%2 == 1){
//             // find
//             return solve(nums1, nums2, target_idx, 0, length_a-1, 0, length_b-1);
//         }
//         else {
//             return 1.0*(solve(nums1, nums2, target_idx, 0, length_a-1, 0, length_b-1)+solve(nums1, nums2, target_idx-1, 0, length_a-1, 0, length_b-1))/2.0;
//         }
//     }
    
//     int solve(vector<int>&nums1, vector<int>&nums2, int idx, int left1, int right1, int left2, int right2){
//         if(left1 > right1){
//             return nums2[idx-left1];
//         }
//         if(left2 > right2){
//             return nums1[idx-left2];
//         }
//         int mid1 = (left1+right1)/2;
//         int mid2 = (left2+right2)/2;
//         if(mid1 + mid2 >= idx){
//             // find left part
//             if(nums1[mid1] < nums2[mid2]){
//                 // remove right2
//                 return solve(nums1, nums2, idx, left1, right1, left2, mid2-1);
//             }
//             else {
//                 // remove right1
//                 return solve(nums1, nums2, idx, left1, mid1-1, left2, right2);
//             }
//         }
//         else {
//             // find right part
//             if(nums1[mid1] < nums2[mid2]){
//                 // remove left1
//                 return solve(nums1, nums2, idx, mid1+1, right1, left2, right2);
//             }
//             else {
//                 // remove left2
//                 return solve(nums1, nums2, idx, left1, right1, mid2+1, right2);
//             }
//         }
        
//         return -1;
//     }
    
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // reference: https://www.youtube.com/watch?v=q6IEA26hvXc
        
        // 1 2 3   4   5 6
        //     l2  r2
        // 1 2 3   4  5  6   #find the 6th smallest and 7th smallest
        //     l1  r1
        int n1 = nums1.size(), n2 = nums2.size();
        if(n1 > n2){
            return findMedianSortedArrays(nums2, nums1);
        }
        // find the mediem point of nums1 and then we know how many number we should count in nums2
       
        int low = 0, high = nums1.size()-1;
        int mid = (low+high+1)/2;
        int k = (n1+n2)/2;
        //  in other solution , when odd the disirid number of middle index should +1 e.x. [1,3] [2]
        
        while(true){
            cout << low << " " << high << endl;
            // index of the middle point
            int mid1 = floor((low + high) / 2.0);
            int mid2 = k - (mid1+1) -1;
            
            int l1, l2, r1, r2;// the partition point
            if(mid1 >= 0){
                l1 = nums1[mid1];
            }
            else l1 = INT_MIN;
            if(mid2 >= 0){
                l2 = nums2[mid2];
            }
            else l2 = INT_MIN;
            if(mid1 < n1-1){
                r1 = nums1[mid1+1];
            }
            else r1 = INT_MAX;
            if(mid2 < n2-1){
                r2 = nums2[mid2+1];
            }
            else r2 = INT_MAX;
            cout << l1 << " " << r1 << " " << l2 << " " << r2 << endl;
            if(l1 <= r2 && l2 <= r1){
                // correct number of k
                if((n1+n2)%2 == 0){
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                }
                else {
                    return min(r1, r2);
                }
            }
            else if(l1 > r2){
                // 1 need to be less
                high = mid1-1;
            }
            else {
                
                low = mid1+1;
            }
        }
        return 0;
    }
};