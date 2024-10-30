class Solution {
public:
    /*
    [&] The lambda can access and modify variables from the surrounding scope directly.
    
    
    */
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int>mp;
        for(auto &num : nums){
            mp[num] += 1;
        }
        
        sort(nums.begin(), nums.end(), [&](int a, int b){
            if(mp[a] < mp[b]){
                // cout << mp[b] << b << endl;
                // cout << mp[a] <<a <<  endl;
                return true;
            }
            else if(mp[a] > mp[b]){
                // cout << mp[b] << b << endl;
                // cout << mp[a] <<a <<  endl;
                return false;
            }
            else {
                if(a > b)return true;
                else return false;
            }
        });
        return nums;
    
    }
};