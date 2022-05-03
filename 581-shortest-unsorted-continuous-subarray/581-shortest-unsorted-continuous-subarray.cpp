class Solution {
public:
    /*
    method 1 
    O(n^2) the first index will be the smallest and the second will be the second smallest and so on
    if not then the length minus the index.
    
    method 2
    use greedy to find front and end of the unordered sub array
    */
    int findUnsortedSubarray(vector<int>& nums) {
        int max_num = -100001, min_num = 100001;
        int start = nums.size()-1, end = 0;
        // find the end of correct array
        // find the largest num, if 
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] >= max_num) {
                max_num = nums[i];
            }
            else {
                end = i;
            }
        }
        for(int i = nums.size()-1; i > -1; i--){
            if(nums[i] <= min_num){
                min_num = nums[i];
            }
            else {
                start = i;
            }
        }
        // cout << start << " " << end << endl;
        return (end > start) ? (end-start+1): 0;
        
    }
};