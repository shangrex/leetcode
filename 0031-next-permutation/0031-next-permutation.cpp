class Solution {
public:
    /*
    the permuation list is stricly increasing
    123
    132
    213
    231
    312
    321

    The biggest permutation is 3 2 1 strictly decreasing.


    Approach 1.
    First scan from the end of the nums,
        Find the frist decreasing number from the right. Let's say ith index
    Second scan from the ith to the right. Find the smallest number that larger than nums[i]

    Third reverse i+1

    T: O(N)
    S: O(1)
    */
    void nextPermutation(vector<int>& nums) {
        // 1 2 3
        //   i
        // 1 3 2
        // 1 2 4 3
        //.  i. 
        // 1 3 2 4
        // 
        //   4 3 2 1
        // i 
        // first swap the decreasting point and smallest larger point compare to ith
        int i = nums.size()-2;

        while(i >= 0 && nums[i] >= nums[i+1]){
            i--;
        }

        if(i >= 0){
            int j = nums.size()-1;
            while(j >= 0 && nums[j] <= nums[i]){
                j--;
            }

            swap(nums[i], nums[j]);
        }


        reverse(nums.begin()+i+1, nums.end());
    }
};