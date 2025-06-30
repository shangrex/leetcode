class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        /*
        Appraoch 1. use an array to store

        vector<int> keyIndex;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == key){
                keyIndex.push_back(i);
            }
        }

        vector<int>ret;
        int trackIndex = 0;
        for(int i = 0; i < nums.size(); i++){
            if(abs(keyIndex[trackIndex] - i) <= k){
                ret.push_back(i);
            }
            else if(trackIndex < keyIndex.size()-1 && abs(keyIndex[trackIndex+1] - i) <= k){
                ret.push_back(i);
                trackIndex++;
            }
        }
        return ret;
        Approach 2. two pointer
        */
        vector<int>ret;
        int n = nums.size();
        int r = 0;
        for(int i = 0;i < n; i++){
            if(nums[i] == key){
                int l = max(i-k, r);
                r = min(n-1, i+k)+1;
                for(int j = l; j < r; j++){
                    ret.push_back(j);
                }
            }
        }
        return ret;
    }
};