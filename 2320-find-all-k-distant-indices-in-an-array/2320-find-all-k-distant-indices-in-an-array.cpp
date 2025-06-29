class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
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
    }
};