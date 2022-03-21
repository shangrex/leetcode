class Solution {
public:
    /*
    1. bruce force with n^2
    2. sort and find the intersection
        a. sort
        b. compare if same  add to vector otherwise add small one
    */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> rst;
        if(nums1.size() == 0 || nums2.size() == 0)return rst;
        int l = 0, r = 0, tmp = nums1[0]-1;
        while(l < nums1.size() && r < nums2.size()){
            if(nums1[l] == nums2[r] && nums1[l] != tmp){
                rst.push_back(nums1[l]);
                tmp = nums1[l];
                l++;
                r++;
            }
            else if(nums1[l] < nums2[r]){
                l++;
            }
            else if(nums1[l] > nums2[r]){
                r++;
            }
            else {
                l++;
                r++;
            }
        }
        return rst;
    }
};