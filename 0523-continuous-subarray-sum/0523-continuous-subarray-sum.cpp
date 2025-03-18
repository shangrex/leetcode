class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        /*
        Hint: (prefix[k] - prefix[l]) %k ==0
        means prefix[k] %k == prefix[l]%k
        */
        int prefix_Mod = 0;
        unordered_map<int, int> modSeen;
        modSeen[0]= -1;
        // 1 2
        // 2 3
        // 0 1 2 3
        // 1 0
        for(int i = 0; i < nums.size(); i++){
            prefix_Mod = (prefix_Mod + nums[i] ) % k;
            if(modSeen.find(prefix_Mod) != modSeen.end()){
                if(i - modSeen[prefix_Mod] > 1){
                    return true;
                }
            }
            else modSeen[prefix_Mod] = i;
        }   
        return false;
    }
};