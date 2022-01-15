#include <algorithm>    // std::reverse

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        /*
        A1 
        square all and sort again
        O(nlgn)
        
        A2
        since the given array is non-decreasing, check the head and tail and compare
        the absolute bigger one would be put in the new array.
        
        reverse the new array
        
        follow up:
        what is the operate of abs()
        
        */
        
        vector<int>rst;
        int first = 0, end = nums.size()-1;
        while(first <= end){
            if(abs(nums[first]) > abs(nums[end])){
                rst.push_back(nums[first]*nums[first]);
                first++;
            }
            else {
                rst.push_back(nums[end]*nums[end]);
                end--;
            }
        }
        reverse(rst.begin(), rst.end());
        return rst;
    }
};