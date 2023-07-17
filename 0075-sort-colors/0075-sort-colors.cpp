class Solution {
public:
    /*
    counting sort
    
    */
    void sortColors(vector<int>& nums) {
        map<int, int>mp;
        for(int i = 0;i < nums.size(); i++){
            mp[nums[i]]+=1;
        }
        int iter = 0;
        for(int i = 0; i < mp[0]; iter++, i++){
            nums[iter] = 0;
        }
        for(int i = 0; i < mp[1]; iter++, i++){
            nums[iter] = 1;
        }
        for(int i = 0; i < mp[2]; iter++, i++){
            nums[iter] = 2;
        }
        
    }
};