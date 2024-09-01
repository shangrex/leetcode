class Solution {
public:
    /*
    Approach 1. Merge Sort or two pointer
    Approach 2. Binary search
        * recursive 
        * while loop
    */
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int length_a = nums1.size(), length_b = nums2.size();
        int target_idx = (length_a+length_b)/2;
        if((length_a+length_b)%2 == 1){
            // find
            return solve(nums1, nums2, target_idx, 0, length_a-1, 0, length_b-1);
        }
        else {
            return 1.0*(solve(nums1, nums2, target_idx, 0, length_a-1, 0, length_b-1)+solve(nums1, nums2, target_idx-1, 0, length_a-1, 0, length_b-1))/2.0;
        }
    }
    
    int solve(vector<int>&nums1, vector<int>&nums2, int idx, int left1, int right1, int left2, int right2){
        if(left1 > right1){
            return nums2[idx-left1];
        }
        if(left2 > right2){
            return nums1[idx-left2];
        }
        int mid1 = (left1+right1)/2;
        int mid2 = (left2+right2)/2;
        if(mid1 + mid2 >= idx){
            // find left part
            if(nums1[mid1] < nums2[mid2]){
                // remove right2
                return solve(nums1, nums2, idx, left1, right1, left2, mid2-1);
            }
            else {
                // remove right1
                return solve(nums1, nums2, idx, left1, mid1-1, left2, right2);
            }
        }
        else {
            // find right part
            if(nums1[mid1] < nums2[mid2]){
                // remove left1
                return solve(nums1, nums2, idx, mid1+1, right1, left2, right2);
            }
            else {
                // remove left2
                return solve(nums1, nums2, idx, left1, right1, mid2+1, right2);
            }
        }
        
        return -1;
    }
};