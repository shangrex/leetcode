class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return {-1, -1};
        vector<int> ret;

        int left = 0, right = nums.size()-1;
        // [5,7,7,8,8,10]
        //  l          r
        //      m
        //.       l
        //          m
        //          r
        //         m
        //         r
        // [1]

        while(left < right){
            int mid = left + (right - left) /2;
            if(nums[mid] < target){
                left = mid+1;
            }
            else right = mid;
        }
        if(nums[left] == target)
            ret.push_back(left);
        else return {-1, -1};

        // [5,7,7,8,8,10]
        //. l          r
        //.     m
        //        l.   
        //          m
        //             l
        //             m
        //             r
        left = 0;
        right = nums.size()-1;
        while(left <= right){
            int mid = left + (right - left) /2;
            if(nums[mid] <= target){
                left = mid+1;
            }
            else right = mid-1;
        }

        
        ret.push_back(right);

        return ret;
    }
};