class Solution {
public:
    /*
    approach 1: create a new array and copy the original array to new array by add k index
    time: O(N)
    space: O(N)
    
    approach 2: rotate 1 in k times
    time: O(kN)
    space: O(1)
    
    approach 3: Cyclic Replacements
    time: O(N)
    space: O(1)
    
    appoatch 4: reverse
    
    approach 5: 
    */
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
    reverse(nums.begin(), nums.end() - k);
    reverse(nums.end()-k  , nums.end());
    reverse(nums.begin(), nums.end());
    }
};